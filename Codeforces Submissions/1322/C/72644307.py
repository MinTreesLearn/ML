import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import Counter
from math import gcd

t=int(input())
for tests in range(t):
    n,m=map(int,input().split())
    C=list(map(int,input().split()))
    X=[[] for i in range(n+1)]

    for k in range(m):
        x,y=map(int,input().split())
        X[y].append(x)

    #print(X)

    A=Counter()
    for i in range(n):
        A[hash(tuple(sorted(X[i+1])))]+=C[i]

    #print(A)

    ANS=0
    for g in A:
        if g==hash(tuple()):
            continue
        ANS=gcd(ANS,A[g])

    print(ANS)
    _=input()
        
    
