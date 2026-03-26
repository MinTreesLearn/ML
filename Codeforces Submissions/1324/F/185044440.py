def rerooting():  
  dp=[[E]*len(edge[v]) for v in range(n)]
  
  # dfs1
  memo=[E]*n
  for v in order[::-1]:
    res=E
    for i in range(len(edge[v])):
      if edge[v][i]==par[v]:
        continue
      dp[v][i]=memo[edge[v][i]]
      res=merge(res,f(dp[v][i],edge[v][i]))
    memo[v]=g(res,v)
  
  # dfs2
  memo2=[E]*n
  for v in order:
    for i in range(len(edge[v])):
      if edge[v][i]==par[v]:
        dp[v][i]=memo2[v]
    
    s=len(edge[v])
    cumR=[E]*(s+1)
    cumR[s]=E
    for i in range(s,0,-1):
      cumR[i-1]=merge(cumR[i],f(dp[v][i-1],v))
      
    cumL=E
    for i in range(s):
      if edge[v][i]!=par[v]:
        val=val=merge(cumL,cumR[i+1])
        memo2[edge[v][i]]=g(val,v)
      cumL=merge(cumL,f(dp[v][i],edge[v][i]))
  
  
  ans=[E for i in range(n)]

  for v in range(n):
    res=E
    for i in range(len(edge[v])):
      res=merge(res,f(dp[v][i],edge[v][i]))
    ans[v]=g(res,v)
    #ans[v]=calc_ans(res,v)

  return ans



E=0

def f(res,v):
  return max(res,0)
 
def g(res,v):
  if c[v]==1:
    return res+1
  return res-1
 
def merge(a,b):
  return a+b

'''
def calc_ans(res,v):
  return
'''


from sys import stdin
input=lambda :stdin.readline()[:-1]



n=int(input())
edge=[[] for i in range(n)]
c=list(map(int,input().split()))
for i in range(n-1):
  x,y=map(lambda x:int(x)-1,input().split())
  edge[x].append(y)
  edge[y].append(x)



# make order table
# root = 0

from collections import deque
order=[]
par=[-1]*n
todo=deque([0])
while todo:
  v=todo.popleft()
  order.append(v)
  for u in edge[v]:
    if u!=par[v]:
      par[u]=v
      todo.append(u)

ans=rerooting()
print(*ans)