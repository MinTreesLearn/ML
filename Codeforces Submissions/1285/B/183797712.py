import math as mt
from collections import defaultdict,deque
import sys
from bisect import bisect_right as b_r
from bisect import bisect_left as b_l
# from os import path
# from heapq import *


mod=1000000007
INT_MAX = sys.maxsize-1
INT_MIN = -sys.maxsize



# if(path.exists('inputt.txt')):
#     sys.stdin = open('inputt.txt','r')
#     sys.stdout = open('output.txt','w')
# else:
#     # input=sys.stdin.readline
#     pass

input = lambda: sys.stdin.readline().rstrip("\r\n")

def myyy__answer():
    n=int(input())
    a=list(map(int,input().split()))

    ans=INT_MIN;temp=0

    for i in range(n-1):
        ans=max(ans,temp+a[i])

        temp+=a[i]
        if(temp<0):
            temp=0

    temp=0
    for i in range(1,n):
        ans=max(ans,temp+a[i])

        temp+=a[i]
        if(temp<0):
            temp=0

    # print(sum(a),ans)

    if(sum(a)>ans):
        print("YES")
    else:
        print("NO")






    
        


    
    
    

if __name__ == "__main__":
    for _ in range(int(input())):
        # print(myyy__answer())
        myyy__answer()