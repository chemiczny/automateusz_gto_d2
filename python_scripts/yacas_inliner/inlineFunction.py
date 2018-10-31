#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 12:34:50 2018

@author: michal
"""
import re

class YacasInlineFunction:
    def __init__(self, lineNo):
        self.name = ""
        self.input = []
        self.output = []
        
        self.body = ""
        self.lineStart = lineNo
        self.lineStop = lineNo
        
    def readFromFile(self, file):
        lineWithName = file.readline()
        self.nameFromLine(lineWithName)
        self.argumentsFromLine(lineWithName)
        
        bracketsDiff = lineWithName.count("[") - lineWithName.count("]")
        
        line = file.readline()
        bracketsDiff += line.count("[") - line.count("]")
        
        lastLine = ""
        while bracketsDiff > 0:
            self.body += lastLine
            lastLine = line
            line = file.readline()
            self.lineStop += 1
            bracketsDiff += line.count("[") - line.count("]")
            
        self.outputFromLine(lastLine)
        
        
    def nameFromLine(self, line):
        if not "Function" in line:
            name = line.split("(")[0]
            self.name = name.strip()
        else:
            name = line.split('"')[1]
            self.name =name
            
    def argumentsFromLine(self, line):
        if not "Function" in line:
            fragment = line.split("(")[1].split(")")[0]
            fragment = fragment.replace("_", "")
            fragments = fragment.split(",")
            self.input = [ s.strip() for s in fragments]
        else:
            fragment = line.replace("{" , "dupa")
            fragment = line.replace("}", "dupa" )
            fragments = line.split("dupa")
            self.input = [ s.strip() for s in fragments]
        
    def outputFromLine(self, line):
        if "{" in line and "}" in line:
            fragment = line.strip()
            fragment = fragment.replace("{" ,"")
            fragment = fragment.replace("}", "")
            fragment = fragment.replace(";", "")
            fragments = fragment.split(",")
            
            self.output = [ s.strip() for s in fragments]
            
        else:
            fragment = line.replace(";", "")
            self.output =  [ fragment.strip() ]
            
    def createMapping(self, rightVariables, leftVariables ):
        inputInputMapping = {}
        outputOutputMapping = {}
#        print(rightVariables)
#        print(self.input)
#        print
        
        for rv, outp in zip(leftVariables, self.output):
#            if rv != outp:
            outputOutputMapping[ r"\b" +  outp + r"\b" ] = rv
        
        deathMapping = {}
        for lv, inp in zip(rightVariables, self.input):
            if lv != inp and inp in self.output:
                inputInputMapping[ r"\b" +  inp + r"\b" ] = lv
            elif '"' in lv :
                inputInputMapping[ r"\b" +  inp + r"\b" ] = lv
            elif inp not in self.output  :
                deathMapping[r"\b" +  lv + r"\b" ] = lv+"localize"
                inputInputMapping[ r"\b" +  inp + r"\b" ] = lv+"localize"
            
                
            
            
        varMapping = {}
#        print(inputInputMapping)
#        print(outputOutputMapping)
        varMapping.update(inputInputMapping)
        varMapping.update(outputOutputMapping)
        
        return varMapping, deathMapping
    
    def updateMapping(self, localLine, mapping):
        localLine = localLine.replace("Local(", "")
        localLine = localLine.replace(");" , "" )
        
        localVariables = [ fr.strip() for fr in localLine.split("," )]
#        print(mapping)
        for lv in localVariables:
            lvKey = r"\b" + lv + r"\b"
#            print(lvKey)
            if not lvKey in mapping:
#                print(lv, mapping)
                mapping[lvKey] = lv + "local"
#        print(mapping)
        return mapping
    
    def writeInlined(self,mapping, file2write, deathMapping ):
        bodyLines = self.body.split("\n")
        offset = -1
        for var in deathMapping:
            file2write.write(deathMapping[var] + ":= DeepCopy(" + var.replace(r"\b", "")+");\n")
#        print(mapping)
        for line in bodyLines:
#            print(line)
            if "Local(" in line:
                mapping = self.updateMapping(line, mapping)
                continue
            for key in mapping:
                line = re.sub( key , mapping[key]+"holdThisShit", line)
            line = line.replace("holdThisShit", "")
                
            file2write.write(line+"\n")
            offset += 1
#            print(line)
        return offset