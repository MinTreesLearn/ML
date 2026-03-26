from functools import lru_cache
n=int(input())
a=[*map(int,input().split())]
@lru_cache(None)
def dfs(even,odd,tail):
    if even<0 or odd<0:
        return n
    if even==0 and odd==0:
        return 0
    idx=even+odd-1
    if a[idx]==0:
        return min(dfs(even-1,odd,0)+tail,dfs(even,odd-1,1)+1-tail)
    if a[idx]&1:
        return dfs(even,odd-1,1)+1-tail
    else:
        return dfs(even-1,odd,0)+tail
print(min(dfs(n>>1,n+1>>1,0),dfs(n>>1,n+1>>1,1)))