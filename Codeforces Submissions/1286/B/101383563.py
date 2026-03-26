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
flag=1
def dfs(i,p=-1,val=1):
	c=0
	for j in a[i]:
		if j!=p:
			c+=dfs(j,i,val+c)
	if c<ch[i]:
		flag=0
		return False		
	c+=1
	for j in a[i]:
		if j!=p:
			dfs2(j,i,val+ch[i])
	ans[i]=val+ch[i]		
	return c		
def dfs2(i,p=-1,val=1):
	if ans[i]>=val:
		ans[i]+=1
	for j in a[i]:
		if j!=p:
			dfs2(j,i,val)

while t>0:
	t-=1
	n=fi()
	a=[[] for i in range(n+1)]
	ch=[0]*(n+1)
	ans=[0]*(n+1)
	for i in range(n):	
		p,c=mi()
		ch[i+1]=c
		if p==0:
			root=i+1
		else:
			a[p].append(i+1)
			a[i+1].append(p)	
	dfs(root)
	if flag==0 or ans[1:].count(0):
		print("NO")
		continue
	print("YES")		
	print(*ans[1:])	