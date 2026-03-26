import sys,math
input=sys.stdin.readline
INF=int(1e9)+7

def solve():
    n=int(input())
    data=[list(map(int,input().split())) for _ in range(n)]
    if n%2!=0:
        print("NO"); return
    for i in range(n//2):
        if data[i][0]+data[i+n//2][0]!=data[0][0]+data[n//2][0]:
            print("NO"); return
        if data[i][1]+data[i+n//2][1]!=data[0][1]+data[n//2][1]:
            print("NO"); return
    print("YES")
    
    
t=1      
#t=int(input())
for i in range(1,t+1):
    solve()
