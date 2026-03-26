import math
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))





for _ in range(inp()):
    n = inp()
    s = insr()
    coord = {(0,0):0}
    left = 0
    up = 0
    maxer = 999999999999999
    coords = None
    for i in range(n):
        if s[i] == 'L':
            left -= 1
        elif s[i] == 'R':
            left += 1
        elif s[i] == 'U':
            up += 1
        else:
            up -= 1
        if (left, up) in coord:
            if i+1 - coord[(left, up)] < maxer:
                maxer = i+1 - coord[(left, up)]
                coords = (coord[(left, up)], i+1)
        coord[(left, up)] = i+1
    if maxer == 999999999999999:
        print(-1)
    else:
        print(coords[0]+1, coords[1])
