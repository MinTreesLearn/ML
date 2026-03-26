import sys,math
input=sys.stdin.readline
INF=int(1e9)+7

def solve():
    n=int(input())
    data=list(map(int,input().split()))
    cnt=[[] for _ in range(33)]
    cut=[False]*33
    visited=[False]*n
    for i in range(n):
        for j in range(30):
            if (1<<j)&data[i]:
                cnt[j].append(i)
    result=[]
   # print(cnt)
    for i in range(31,-1,-1):
        if len(cnt[i])!=1 or cut[i]:
            continue
        else:
            if not visited[cnt[i][0]]:
                result.append(cnt[i][0])
                visited[cnt[i][0]]=True
                for j in range(30):
                    if (1<<j)&data[cnt[i][0]]:
                        cut[j]=True
    for i in range(n):
        if not visited[i]:
            result.append(i)
    for i in range(n):
        print(data[result[i]],end=' ')
    print()
    
    
t=1      
#t=int(input())
for i in range(1,t+1):
    solve()
