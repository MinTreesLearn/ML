import  threading
import sys
from sys import stdin
input=stdin.readline
sys.setrecursionlimit(10**8)
from collections import  defaultdict
def main():
    n=int(input())
    arr=list(map(int,input().split()))
    graph=[[] for _ in range(n)]
    for _ in range(n-1):
        a,b=map(int,input().split())
        a-=1
        b-=1
        graph[a].append(b)
        graph[b].append(a)
    idea={}
    def dfs(node,par):
        ans=0
        f=False
        for nie in graph[node]:
            if nie!=par:
                dfs(nie,node)
                if idea[nie]>=0:
                    ans+=idea[nie]
                    f=True
        ans-=1 if arr[node]==0 else -1
        idea[node]=ans
    dfs(0,-1)
    ans=[0]*(n)
    def dfs1(node,par):
        if par==-1:
            ans[node]=idea[node]
        else:
            ans[node]=idea[node]+max(0,idea[par]-(idea[node] if idea[node]>=0 else 0))
            idea[node]+=max(0,idea[par]-(idea[node] if idea[node]>=0 else 0))
        for nie in graph[node]:
            if nie!=par:
                dfs1(nie,node)
    dfs1(0,-1)
    print(*ans)
             
 
threading.stack_size(10 ** 8)
t = threading.Thread(target=main)
t.start()
t.join()