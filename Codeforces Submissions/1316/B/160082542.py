import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    
    s=input().rstrip()
    
    a=[[s,1]]
    for i in range(1,n-1):
        h=n-i
        if h%2==0:a.append([s[i:]+s[:i],i+1])
        else:
            v=s[:i]
            a.append([s[i:]+v[::-1],i+1])
    a.append([s[::-1],n])
    b=sorted(a,key=lambda x:(x[0],x[1]))
    print(b[0][0])
    print(b[0][1])