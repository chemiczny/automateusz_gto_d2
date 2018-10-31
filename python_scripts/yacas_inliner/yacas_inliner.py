#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 29 14:29:50 2018

@author: michal
"""
from os.path import dirname, basename, join
import networkx as nx
from functionCall import FunctionCall
from inlineFunction import YacasInlineFunction
from shutil import copyfile
from os import remove
import re
        
class YacasInliner:
    def __init__(self, yacasFile = "/home/michal/Projects/automateusz_gto_d2/yacas_scripts/emit_eri_d2_divided.ys"):
        self.yacasMainFile = yacasFile
        self.yacasMainFileBasename = basename(yacasFile)
        self.yacasFileDir = dirname(yacasFile)
        
        self.inlineFunctions = []
        self.inlineFunctionsCalls = []
        self.dependencyGraph = None
        self.dependencyFiles = []

    def findDependencies(self,  yacasFileBasename, yacasDir ):
        yFiles = set()
        yacasFile = join(yacasDir, yacasFileBasename)
        with open(yacasFile) as ysF:
            line = ysF.readline()
            
            while line:
                if "Use" in line or "Load" in line:
                    newFile = line.split("(")[1].split(")")[0]
                    newFile = newFile.replace('"', "")
                    
                    yFiles.add(newFile)
                
                line = ysF.readline()
                
        return yFiles

    def findAllDependencies( self):
        self.dependencyGraph = nx.DiGraph()
        
        yFiles2process = set([self.yacasMainFileBasename])
        self.dependencyFiles = set()
        while yFiles2process:
            yFile = yFiles2process.pop()
            newFiles = self.findDependencies(yFile, self.yacasFileDir)
            yFiles2process |=  newFiles - self.dependencyFiles
            self.dependencyFiles.add( yFile )
            
            for nf in newFiles:
                self.dependencyGraph.add_edge(yFile, nf)
            

    def findInlineFunctions(self):
        self.inlineFunctions = []
        
        for yF in self.dependencyGraph.nodes():
            if "processed" in self.dependencyGraph.node[yF]:
                self.inlineFunctions +=  self.findInlineFunctionsInFile(self.dependencyGraph.node[yF]["processed"], self.yacasFileDir)
            else:
                self.inlineFunctions +=  self.findInlineFunctionsInFile(yF, self.yacasFileDir) 
            

    def findInlineFunctionsInFile(self, yacasFileBasename, yacasDir):
        yacasFile = join(yacasDir, yacasFileBasename)
        inlineFunctions = []
        lineNo = 1
        with open(yacasFile) as ysF:
            line = ysF.readline()
            
            while line:
                if  re.search(r"\b" +  "\\inline" + r"\b" , line ):
                    newInlineFunction = YacasInlineFunction(lineNo)
                    newInlineFunction.readFromFile(ysF)
                    inlineFunctions.append(newInlineFunction)
                lineNo += 1
                line = ysF.readline()
        
        return inlineFunctions

    def findInlineFunctionCallInFile(self, yacasFileBasename, yacasMainFile, yacasDir):
        
        yacasFile = join(yacasDir, yacasFileBasename)
        if "processed" in self.dependencyGraph.node[yacasFileBasename]:
            yacasFile = join(yacasDir, self.dependencyGraph.node[yacasFileBasename]["processed"])
        inlineFunctionsCall = []
        actualFunction = None
        lineNo = 1
        
        with open(yacasFile) as ysF:
            line = ysF.readline()
            
            while line:
                if "<--" in line:
                    actualFunction = line.split("(")[0].strip()
                else:
                    for inlfun in self.inlineFunctions:
                        if re.search( r"\b" +  re.escape(inlfun.name) + r"\b" , line ) and not "//" == line.strip()[:2] :
                            newInlineFunCall = FunctionCall()
                            newInlineFunCall.insideFunction = actualFunction
                            newInlineFunCall.inlineFunName = inlfun
                            newInlineFunCall.callFile = yacasFileBasename
                            newInlineFunCall.distance2main = self.dependencyGraph.number_of_edges( yacasMainFile, yacasFileBasename)
                            newInlineFunCall.argumentsFromLine(line)
                            newInlineFunCall.lineNo = lineNo -1 
                            
                            if newInlineFunCall.argumentsNo == len(inlfun.input):
                                inlineFunctionsCall.append(newInlineFunCall)
                lineNo += 1
                line = ysF.readline()
        
        return inlineFunctionsCall

    def findAllInlineCalls( self  ):
        self.inlineFunctionsCalls = []
#        print(self.dependencyGraph.nodes(True))
        for yacasFile in self.dependencyGraph.nodes():
                self.inlineFunctionsCalls += self.findInlineFunctionCallInFile(yacasFile , self.yacasMainFileBasename ,  self.yacasFileDir)
            

    def inlineFiles( self):
        self.inlineFunctionsCalls = sorted(self.inlineFunctionsCalls)
        self.inlineFunctionsCalls.reverse()
#        print("lot?", len(self.inlineFunctionsCalls))
        for ic in self.inlineFunctionsCalls:
#            print(ic.callFile)
            self.inlineFileAndDependencies( ic,  self.yacasFileDir)
            print("inlinuje ", ic.callFile)
            break
    
    def inlineFileAndDependencies( self, inlineCall, yacasDir):
        need2remove = False
        if not "processed" in self.dependencyGraph.node[inlineCall.callFile]:
#            print("zaprocesowalem",inlineCall.callFile )
            processFile = inlineCall.callFile.replace(".ys", "") + "_inlined.ys"
            self.dependencyGraph.node[inlineCall.callFile]["processed"] = processFile
            file2process = join(yacasDir, inlineCall.callFile)
            fileProcessed = join(yacasDir, processFile)
        else:
            
            tempFile = self.dependencyGraph.node[inlineCall.callFile]["processed"].replace(".ys", "_temp.ys" ) 
            file2process = join(yacasDir,tempFile )
            
            fileProcessed = join(yacasDir,self.dependencyGraph.node[inlineCall.callFile]["processed"] )
            copyfile(fileProcessed, file2process)
            need2remove = True
            
#            inlineCall.lineNo +=  self.dependencyGraph.node[inlineCall.callFile]["offset"] 
        
        fsource = open(file2process, 'r')
        fout = open(fileProcessed, 'w')
        
        print(inlineCall.lineNo)
        line = fsource.readline()
        while not line == inlineCall.callLine:
            fout.write(line)
            line = fsource.readline()
            
            
        print(line)
        lineWithCall =  line
        
        inlFun = self.getProperInlineFun(inlineCall)
        
        
        offset = self.insertFunctionBody(fout, lineWithCall, inlFun)
        #TODO to trzeba zrobic lepiej!!!
        self.dependencyGraph.node[inlineCall.callFile]["offset"] = offset
        
        while line:
            line = fsource.readline()
            fout.write(line)
        
        fsource.close()
        fout.close()
        
        if need2remove:
            remove(file2process)
            
        self.inlineDependencies(inlineCall.callFile)
            
    def insertFunctionBody(self, file2write, lineWithCall, inlineFunction ):
        lineSplitted = lineWithCall.split(":=")
        left = lineSplitted[0]
        right = lineSplitted[-1]
        
        if "{" in left and "}" in left:
            left = left.replace("{" , "")
            left = left.replace("}" , "")
            left = left.replace(";", "")
            left = left.split(",")
            leftVariables = [ el.strip() for el in left ]
        else:
            leftVariables = [ left.strip() ]
            
        right = right.replace(inlineFunction.name , "")
        right = right.replace("(", "")
        right = right.replace(")", "")
        right = right.replace(";", "")
        rightVariables = [ el.strip() for el in right.split(",") ]
        
        mapping, deathMapping = inlineFunction.createMapping( rightVariables, leftVariables )
        offset = inlineFunction.writeInlined(mapping, file2write, deathMapping)
        
        return offset
    
    def getProperInlineFun(self, inlCall):
        for inlFun in self.inlineFunctions:
            if inlCall.argumentsNo == len(inlFun.input) and inlCall.inlineFunName.name == inlFun.name:
                return inlFun
            
    def inlineDependencies(self, node ):
        updateInclude = list(self.dependencyGraph.predecessors(node))
        
        for file2update in updateInclude:
            print("poprawiam naglowki ", file2update)
            self.updateInclude( node, file2update )
            self.inlineDependencies(file2update)
        
    def updateInclude(self, nodeSource, node2update):
        need2remove = False
        if not "processed" in self.dependencyGraph.node[node2update]:
#            print("zaprocesowalem",node2update )
            processFile = node2update.replace(".ys", "") + "_inlined.ys"
            self.dependencyGraph.node[node2update]["processed"] = processFile
            file2process = join(self.yacasFileDir, node2update)
            fileProcessed = join(self.yacasFileDir, processFile)
        else:
            tempFile = self.dependencyGraph.node[node2update]["processed"].replace(".ys", "_temp.ys" ) 
            file2process = join(self.yacasFileDir,tempFile )
            
            fileProcessed = join(self.yacasFileDir,self.dependencyGraph.node[node2update]["processed"] )
            copyfile(fileProcessed, file2process)
            need2remove = True
            
        fsource = open(file2process, 'r')
        fout = open(fileProcessed, 'w')
        
        line = True
        while line:
            line = fsource.readline()
            if "Use" in line or "Load" in line:
                if nodeSource in line:
                    line = line.replace( nodeSource, self.dependencyGraph.node[nodeSource]["processed"] )
            fout.write(line)
        
        if need2remove:
            remove(file2process)

    def run(self):
        self.findAllDependencies()
        self.findInlineFunctions()
        self.findAllInlineCalls()
        i = 0
        while self.inlineFunctionsCalls:
            print("iteracja", i, len(self.inlineFunctionsCalls))
            print("znalezione inline callsy:")
            for ic in self.inlineFunctionsCalls:
                print(ic.callFile, ic.inlineFunName.name, ic.argumentsNo)
            self.inlineFiles()
            self.findInlineFunctions()
            self.findAllInlineCalls()
            i+=1
        
        
ysInliner = YacasInliner()
ysInliner.run()

