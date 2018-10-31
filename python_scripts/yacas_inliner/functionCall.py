#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 30 12:34:38 2018

@author: michal
"""

class FunctionCall:
    def __init__(self):
        self.callFile = ""
        self.insideFunction = ""
        self.lineNo = -1
        self.inlineFunName = ""
        self.argumentsNo = -1
        self.distance2main = -1
        
        self.callLine = ""
        
    def argumentsFromLine(self, line):
        self.callLine = line
        fragment = line.split("(")[1].split(")")[0]
        fragment = fragment.replace("_", "")
        fragments = fragment.split(",")
        self.argumentsNo = len(fragments)
        
    def __eq__(self, other):
        return self.distance2main == other.distance2main 

    def __lt__(self, other):
        return self.distance2main < other.distance2main