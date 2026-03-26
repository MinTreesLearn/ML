from math import * 
from heapq import heappop, heappush
MOD = 10**9 + 7
#input=sys.stdin.readline

    #map(int, input().split())
    #list(map(int, input().split()))
class Solution():
    pass

def areYouCool(n,a,b, amount):
    for val in range(1, min(a//amount, n-1) + 1):
        if (b//amount) + val >= n:
            return True
    return False

def solution():
    # length n and m fs
    # what is the  maximam
    # 0010010 --> 2 ones --> this means there is only 2
    # 5//3 --> 2
    # 3 + 3 + 1 --> 7 
    # 7*4 --> 28

    # 000010000001   2
    # 000100010000   2

    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        if m == 0:
            print(0)
            continue

        zeros = n - m
        
        total = (n*(n+1))//2 
        if zeros <= m:
            print(total - zeros)
            continue
        
        m += 1
        k = zeros // m
        l = zeros % m
        
        # few of them will have k + 1
        res = total - l*((k+1)*(k+2))//2 - (m-l)*(k*(k+1))//2
        print(res)
        



 
        

def main():
    #test()
    t = 1
    #t = int(input())
    for _ in range(t):
        solution() 

import sys
import threading
sys.setrecursionlimit(10**6)
threading.stack_size(1 << 27)
thread = threading.Thread(target=main)
thread.start(); thread.join()
#main()
