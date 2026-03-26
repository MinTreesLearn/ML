import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,s=input().rstrip().split()
    n=int(n)
    last=0
    num=n
    ans1=[0]*n
    for i in range(n):
        if i==n-1 or s[i]==">":
            for j in range(last,i+1)[::-1]:
                ans1[j]=num
                num-=1
            last=i+1
    print(*ans1)
    num=1
    last=0
    ans2=[0]*n
    for i in range(n):
        if i==n-1 or s[i]=="<":
            for j in range(last,i+1)[::-1]:
                ans2[j]=num
                num+=1
            last=i+1
    print(*ans2)