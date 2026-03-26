from sys import setrecursionlimit
setrecursionlimit(10 ** 6)
n = int(input())
c = [0 for i in range(n + 1)]
a = [0 for i in range(n + 1)]
g = [[] for i in range(n + 1)]
def dfs(x):
    List = []
    for i in g[x]:
        List += dfs(i)
    if c[x] > len(List):
        raise ValueError
    List.insert(c[x], x)
    return List

for i in range(1,n + 1):
    pi, ci = list(map(int, input().split(' ')))
    c[i] = ci
    g[pi].append(i)

try:
    ans = dfs(0)
    print("YES")
    for i in range(0, n + 1):
        a[ans[i]] = i
    for i in range(1, n + 1):
        print(a[i], end = ' ')
except ValueError:
    print("NO")
 									    	 		 		 				  			