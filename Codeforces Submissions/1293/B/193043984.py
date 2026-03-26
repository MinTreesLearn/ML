from math import * 
import sys
input = lambda: sys.stdin.readline().strip()
print = lambda *a, **kw: sys.stdout.write(kw.get('sep', ' ').join(map(str, a)) + kw.get('end', '\n'))
debug = lambda *a: sys.stderr.write(' '.join(map(str, a)) + '\n')
MOD = (10**9)+7
def prefixSum(arr):
    n=len(arr)
    if(n==0):
        return []
    ps = [0] * n
    ps[0] =arr[0]
    for i in range(1,n):
        ps[i]=arr[i]+ps[i-1]
    return ps
def sumDigits(no):
    return 0 if no == 0 else int(no % 10) + sumDigits(int(no / 10)) 
def inde(arr):
    ind = {}
    for i in range(len(n)):
        ind[arr[i]]=i
    return ind
def freq(arr):
    d = {}
    for i in arr:
        if(i in d):
            d[i]+=1
        else:
            d[i]=1
    return d
def isPrime(num):
    if(num > 1):
        for i in range(2,int(sqrt(num))+1):
            if (num % i == 0):
                return False
        return True
    else:
        return False
def cbrt(num):
    return pow(num,1/3)
    
#for _ in range(int(input())):
n = int(input())
x = 0
for i in range(1,n+1):
    x+=(1/i)
print(x)