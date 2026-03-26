import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    s=input().rstrip()
    p=list(map(int,input().strip().split()))
    a=[0]*n
    for x in p:
        a[x-1]+=1
    a[-1]+=1
    c=0
    for i in range(n-1,-1,-1):
        c+=a[i]
        a[i]=c
    d={}
    for i in range(n):
        d[s[i]]=a[i]+d.get(s[i],0)
    for i in range(97,123):
        print(d.get(chr(i),0),end=' ')
    print()