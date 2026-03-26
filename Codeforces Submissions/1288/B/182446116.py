t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    n=len(str(b))-1
    if str(b)=='9'*(n+1):
        n+=1
    print(a*n)