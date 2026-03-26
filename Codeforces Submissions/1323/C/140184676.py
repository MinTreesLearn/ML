import sys,os,io,math,cmath,timeit,functools,operator,bisect
from collections import defaultdict , Counter
from math import factorial , ceil , floor , inf as INF

ONLINE_JUDGE = 1

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

if not ONLINE_JUDGE :
    sys.stdin = open("C:/Users/mande/Downloads/Practice/Python 3.9.8/inp.in" , "r")
    sys.stdout = open("C:/Users/mande/Downloads/Practice/Python 3.9.8/outp.out" , "w")
    
input = sys.stdin.readline 

start = timeit.default_timer()

primes = []
mod=10**9+7

def power(x,b):
    p=1
    while b>0 :
        if b&1 :
            p=p*x
            p = p%mod
        b = b>>1
        x = x**x
        x = x%mod
    return p%mod
    
def seive(n):
    a = []
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p ** 2,n + 1, p): 
                prime[i] = False
        p = p + 1
    for p in range(2,n + 1): 
        if prime[p]: 
            primes.append(p)

def is_sorted(arr):
    return all(arr[i]<=arr[i+1] for i in range(len(arr)-1))

def invmod(n):
    return power(n,mod-2)

def binary_search(a,x,lo=0,hi=None):
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        midval = a[mid]
        if midval < x:
            lo = mid+1
        elif midval > x: 
            hi = mid
        else:
            return mid
    return -1

def yn(x):
    if x :
        sys.stdout.write("YES"+"\n")
    else :
        sys.stdout.write("NO"+"\n")

def nCr(n,r)->int :
    return factorial(n)//(factorial(r)*factorial(n-r))

def solve()->None :
    n=int(input().strip())
    s=input().strip()
    ans,ct=0,0
    for x in s :
        if x=='(' :
            ct+=1
        else :
            ct-=1
            if ct < 0 :
                ans+=2
    if ct :
        print(-1)
        return
    print(ans)
        

def main():
    tc=1
    #tc=int(input())
    for _ in range(tc):
        solve()
    stop = timeit.default_timer()
    if not ONLINE_JUDGE :
        sys.stdout.write("Time Elapsed : " + str(stop-start) + " seconds")
    sys.stdout.close()

main()