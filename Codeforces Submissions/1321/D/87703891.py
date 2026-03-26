######################################################
############Created by Devesh Kumar###################
#############devesh1102@gmail.com####################
##########For CodeForces(Devesh1102)#################
#####################2020#############################
######################################################
import sys
input = sys.stdin.readline
 
# import sys
import heapq 
import copy
import math
import decimal
 
# import sys.stdout.flush as flush
# from decimal import *
#heapq.heapify(li) 
#
#heapq.heappush(li,4) 
#
#heapq.heappop(li)
#
# &    Bitwise AND Operator    10 & 7 = 2
# |    Bitwise OR Operator    10 | 7 = 15
# ^    Bitwise XOR Operator    10 ^ 7 = 13
 
# <<    Bitwise Left Shift operator    10<<2 = 40
# >>    Bitwise Right Shift Operator
# '''############ ---- Input Functions ---- #######Start#####'''
 
 
def inp():
    return(int(input()))
def inlt(): 
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def insr2():
    s = input()
    return((s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
############ ---- Input Functions ---- #######End
# #####   
 
 
 

def pr_list(a):
    print( *a , sep=" ")
def main():
    # tests =  inp()
    tests = 1
    mod = 1000000007
    limit = 10**18
    ans = 0
    stack = []
    hashm = {}
    arr = []
    heapq.heapify(arr) 

    for test in range(tests):
        [n,m] = inlt()
        grid = [{} for i in range(n+1)]
        grid_r = [{} for i in range(n+1)]
        for _ in range(m):
            [i,j] = inlt()
            grid[i][j] = 1
            grid_r[j][i] = 1
        mini = [ sys.maxsize for i in range(n+1)]
        k = inp()
        p = inlt()
        mini[p[-1]]=0
        stack = [p[-1]]

        while(stack != []):

            nexts =  []
            for i in stack:
                for j in grid_r[i]:
                    if mini[j] ==sys.maxsize:
                        nexts.append(j)
                        mini[j] = mini[i] +1
            stack = nexts
            # print(mini)
        minimum = 0
        maximum = 0
        # print(mini)
        # print(grid)
        for  i in range(0,k-1):
            dist = mini[p[i]]
            dist = dist-1
            valid = []
            minimum = minimum +1
            for j in grid[p[i]]:
                if mini[j] == dist:
                    valid.append(j)
                    if  j == p[i+1]:
                        minimum = minimum -1
            if len(valid) > 1:
                maximum = maximum +1
            elif len(valid) == 1 and valid[0] != p[i+1]:
                maximum = maximum +1
        pr_list([minimum,maximum])
if __name__== "__main__":
    main()
    