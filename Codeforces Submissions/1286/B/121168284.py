from collections import  defaultdict
def dfs(g,node,parent,trees):
	l=0
	for i in g[node]:
		if i!=parent:
			l+=dfs(g,i,node,trees)
	trees[node]=l
	return l+1
def dfs2(g,node,Small,answer,C,trees):
	answer[node]=Small[C[node]]
	supersmall=[]
	for i in range(len(Small)):
		if i!=C[node]:
			supersmall.append(Small[i])
	cnts=0
	for i in g[node]:
		u=[]
		for j in range(trees[i]):
			u.append(supersmall[cnts])
			cnts+=1
		dfs2(g,i,u,answer,C,trees)


n=int(input())
root=None
C=[0]*n
g=defaultdict(list)
for i in range(n):
	parent,c=map(int,input().strip().split())
	if parent==0:
		root=i
	else:
		g[parent-1].append(i)
	C[i]=c

trees=[0]*(n)
dfs(g,root,-1,trees)
check=list(map(lambda x,y:x-y,trees,C))
for i in check:
	if i<0:
		print("NO")
		exit(0)
ans=[0]*n
small=[* range(1,n+1)]
trees=list(map(lambda s:s+1,trees))
dfs2(g,root,small,ans,C,trees)
print("YES")
print(*ans)