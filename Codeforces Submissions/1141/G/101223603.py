import sys
zz=1
 
sys.setrecursionlimit(10**5)
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
di=[[-1,0],[1,0],[0,1],[0,-1]]

def fori(n):
	return [fi() for i in range(n)]	
def inc(d,c,x=1):
	d[c]=d[c]+x if c in d else x
def ii():
	return input().rstrip()	
def li():
	return [int(xx) for xx in input().split()]
def fli():
	return [float(x) for x in input().split()]	
def comp(a,b):
	if(a>b):
		return 2
	return 2 if a==b else 0		
def gi():	
	return [xx for xx in input().split()]
def gtc(tc,ans):
	print("Case #"+str(tc)+":",ans)	
def cil(n,m):
	return n//m+int(n%m>0)	
def fi():
	return int(input())
def pro(a): 
	return reduce(lambda a,b:a*b,a)		
def swap(a,i,j): 
	a[i],a[j]=a[j],a[i]	
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())			
def gh():
	sys.stdout.flush()
def isvalid(i,j,n,m):
	return 0<=i<n and 0<=j<m 
def bo(i):
	return ord(i)-ord('a')	
def graph(n,m):
	for i in range(m):
		x,y=mi()
		a[x].append(y)
		a[y].append(x)


t=1
uu=t

def dfs(i,p=-1,c=-1):
	st=[(i,p,c)]
	vis={}
	while st:
		i,p,c=st[-1]
		if i in vis:
			st.pop()
			continue
		vis[i]=1	
		r=(c+1)%ans
		for j in a[i]:
			if j!=p:
				col[edge[i,j]]=r+1
				st.append((j,i,r))
				r=(r+1)%ans	
		

while t>0:
	t-=1
	d={}
	n,k=mi()
	col=[0]*(n-1)
	d=[0]*(n+1)
	a=[[] for i in range(n+1)]
	edge={}
	for i in range(n-1):
		x,y=mi()
		d[x]+=1
		d[y]+=1
		edge[x,y]=i
		edge[y,x]=i
		a[x].append(y)
		a[y].append(x)
	p={}
	for i in range(1,n+1):
		inc(p,d[i])
	r=[]
	for i in p:
		r.append([i,p[i]])
	r.sort(reverse=True)
	ans=1	
	for i in range(len(r)):
		if k<r[i][1]:
			ans=r[i][0]
			break
		k-=r[i][1]						
	print(ans)
	dfs(1)
	print(*col)	
