# LUOGU_RID: 100980329
for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    print(a[n]-a[n-1])