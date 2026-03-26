def helper(a):
    s=set()
    for i in range(n):
        c=0
        while a[i]>0:
            while a[i]%k==0:
                a[i]//=k
                c+=1
            if a[i]%k==1:
                a[i]-=1
            else:return "NO"
            if c in s:return "NO"
            else:s.add(c)
    return "YES"

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().strip().split()))
    print(helper(a))