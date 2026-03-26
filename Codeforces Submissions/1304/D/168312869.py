import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    arr=list(input().split())
    n=int(arr[0])
    s=arr[1]
    r=[1]
    l=[1]
    c=0
    for i in range(n-1):
        if s[i]=='<':
            r[-1]+=1
            l.append(1)
        else:
            l[-1]+=1
            r.append(1)

    ans1=[0 for _ in range(n)]
    ans2=[0 for _ in range(n)]
    p=n
    p2=0
    for i in range(len(r)):
        for j in range(r[i]):
            ans1[p2]=p-r[i]+1+j
            p2+=1
        p-=r[i]
    p=1
    p2=0
    for i in range(len(l)):
        for j in range(l[i]):
            ans2[p2]=p+l[i]-1-j
            p2+=1
        p+=l[i]
    print(' '.join(map(str,ans1)))
    print(' '.join(map(str,ans2)))
        
