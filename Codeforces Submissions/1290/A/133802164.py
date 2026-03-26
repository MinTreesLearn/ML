import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time, functools, copy,statistics
inf = float('inf')
mod = 10**9+7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def LS(): return input().split()
import time
t = I()
for _ in range(t):
    n, m, k =LI()
    num_list = LI()
    ans = 0
    new_list = num_list[:m]+num_list[-m:]
    new_len = len(new_list)
    if m <= k:
        ans = max(new_list)
    else:
        a = []
        for i in range(k+1):
            if k-i == 0:
                a.append(num_list[i:])
            else:
                a.append(num_list[i:-(k-i)])
        ind = m-1-k
        b= []
        for i in range(len(a)):
            a_len = len(a[i])
            c = []
            for j in range(ind+1):
                if ind - j ==0:
                    c.append(max(a[i][j:][0], a[i][j:][-1]))
                else:
                    c.append(max(a[i][j:-(ind-j)][0],a[i][j:-(ind-j)][-1]))
            b.append(min(c))
        ans = max(b)
    print(ans)


