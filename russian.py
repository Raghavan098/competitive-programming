#!/bin/python

import sys

def revisedRussianRoulette(doors):
    m = 0
    for i in doors:
        if i==1:
            m+=1
    doors.append(0)
    mi = 0
    i = 0
    while(i<len(doors)-1):
        if doors[i]==1:
            mi+=1
            doors[i+1]=0
        i+=1
    return mi,m

if __name__ == "__main__":
    n = int(raw_input().strip())
    doors = map(int, raw_input().strip().split(' '))
    result = revisedRussianRoulette(doors)
    print " ".join(map(str, result))
