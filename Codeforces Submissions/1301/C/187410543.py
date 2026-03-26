
t=int(input())
for test in range(t):
    n,m=map(int,input().split())
    r=(n-m)%(m+1)
    d=(n-m)//(m+1)
    ans=(n-m+r)*(d+1)
    print((n*(n+1) - ans)//2)