import  threading
import sys
from sys import stdin
input=stdin.readline
sys.setrecursionlimit(10**8)
from collections import  defaultdict
def main():
    from functools import lru_cache
    n=int(input())
    arr=list(map(int,input().split()))
    odd=0
    even=0
    for i,el in enumerate(arr):
        if el%2:
            odd+=1
        else :
            even+=1
    odd=n//2+n%2-odd
    even=n//2-even
    @lru_cache(None)
    def solve(i,o,prev):
        if o<0:
            return float("inf")
        if i==n:
            if o:
                return float("inf")
            else :
                return 0
        else :
            if prev==None:
                if arr[i]!=0:
                    ans=solve(i+1,o,arr[i]%2)
                else :
                    ans=min(solve(i+1,o-1,1),solve(i+1,o,0))
            else :
                if arr[i]!=0:
                    ans=int(prev!=arr[i]%2)+solve(i+1,o,arr[i]%2) 
                else :
                    ans=min(int(prev!=1)+solve(i+1,o-1,1),int(prev!=0)+solve(i+1,o,0)  )
            return ans
    print(solve(0,odd,None))

                
    
 
threading.stack_size(10 ** 8)
t = threading.Thread(target=main)
t.start()
t.join()
