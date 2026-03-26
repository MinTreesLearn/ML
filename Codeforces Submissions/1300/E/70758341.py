"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math
input = sys.stdin.readline
############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(s[:len(s) - 1])
def invr():
    return(map(int,input().split()))
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############
t = 1
for tt in range(t):
    n = inp()
    a = inlt()
    a = [(a[i],1) for i in range(len(a))]
    qw = []
    for i in a:
        while len(qw) >= 1 and qw[-1][0] / qw[-1][1]  > i[0] / i[1]:
            q,w = qw.pop()
            i = (i[0] + q,i[1] + w)
        qw.append(i)
    for i in range(len(qw)):
        sys.stdout.write((str(qw[i][0] / qw[i][1]) + "\n") * qw[i][1]) 