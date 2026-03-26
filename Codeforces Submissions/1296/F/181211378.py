
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

def main():
    
    n = int(input())
    adj = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = readIntArr()
        u -= 1; v -= 1
        adj[u].append((v, i))
        adj[v].append((u, i))
    
    m = int(input())
    clues = []
    for _ in range(m):
        u, v, g = readIntArr()
        u -= 1; v -= 1
        clues.append((u, v, g))
    clues.sort(key=lambda arr: arr[2], reverse=True)
    
    ans = [1] * (n - 1)
    # @bootstrap
    # def dfs(u, target):
    #     if u == target:
    #         yield 1
    #     for v, e in adj[u]:
    #         if vi[v] == 0:
    #             vi[v] = 1
    #             edges.append(e)
    #             temp = (yield dfs(v, target))
    #             vi[v] = 0
    #             if temp == 1:
    #                 yield 1
    #             else:
    #                 edges.pop()
    #     yield 0
    
    # Avoid recursion
    nodedepth = [-1] * n
    parnode = [-1] * n
    paredge = [-1] * n
    st = [0]
    nodedepth[0] = 0
    while st:
        u = st.pop()
        for v, e in adj[u]:
            if nodedepth[v] == -1:  # not visited
                nodedepth[v] = nodedepth[u] + 1
                parnode[v] = u
                paredge[v] = e
                st.append(v)
                
        
    
    # vi = [0] * n
    for u, v, g in clues:
        edges = []
        # vi[u] = 1
        # dfs(u, v)
        # vi[u] = 0
        ok = False
        u2, v2 = u, v
        if nodedepth[u] > nodedepth[v]:
            u, v = v, u
        while nodedepth[u] < nodedepth[v]:
            edges.append(paredge[v])
            v = parnode[v]
        while u != v:
            edges.append(paredge[u])
            edges.append(paredge[v])
            u = parnode[u]; v = parnode[v]
        for e in edges:
            if g >= ans[e]:
                ok = True
                ans[e] = g
        if not ok:
            print(-1)
            return
    oneLineArrayPrint(ans)
    
    
    return

import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(a, b):
    print('? {} {}'.format(a, b))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353
 
from math import gcd,floor,ceil
import math
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()