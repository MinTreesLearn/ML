import sys
from collections import defaultdict
import bisect
def f(s,t):
    A=defaultdict(list)
    S=set(s)
    T=set(t)
    for i in T:
        if i not in S:
            return -1
    n=len(s)
    for i in range(n):
        A[s[i]].append(i)
    i=0
    j=0
    U=len(t)
    ans=1
    while j<U:
        c=t[j]
        k=bisect.bisect_left(A[c],i)
        if k>=len(A[c]):
            i=0
            ans+=1
        else:
            j+=1
            i=(A[c][k]+1)
    return ans
n=int(input())
for i in range(n):
    s=input()
    t=input()
    print(f(s,t))


