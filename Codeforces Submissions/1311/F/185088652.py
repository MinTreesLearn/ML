from sys import stdin
input=lambda :stdin.readline()[:-1]

class segtree():
  def __init__(self,init,func,ide):
    self.n=len(init)
    self.func=func
    self.ide=ide
    self.size=1<<(self.n-1).bit_length()
    self.tree=[self.ide for i in range(2*self.size)]
    for i in range(self.n):
      self.tree[self.size+i]=init[i]
    for i in range(self.size-1,0,-1):
      self.tree[i]=self.func(self.tree[2*i], self.tree[2*i|1])
  
  def update(self,k,x):
    k+=self.size
    self.tree[k]=x
    k>>=1
    while k:
      self.tree[k]=self.func(self.tree[2*k],self.tree[k*2|1])
      k>>=1
  
  def get(self,i):
    return self.tree[i+self.size]
  
  def query(self,l,r):
    l+=self.size
    r+=self.size
    l_res=self.ide
    r_res=self.ide
    while l<r:
      if l&1:
        l_res=self.func(l_res,self.tree[l])
        l+=1
      if r&1:
        r-=1
        r_res=self.func(self.tree[r],r_res)
      l>>=1
      r>>=1
    return self.func(l_res,r_res)
  
  def debug(self,s=10):
    print([self.get(i) for i in range(min(self.n,s))])

n=int(input())
x=list(map(int,input().split()))
v=list(map(int,input().split()))
s=sorted(list(set(x)))
d={}
m=len(s)
for i in range(m):
  d[s[i]]=i

seg1=segtree([0]*m,lambda x,y:x+y,0)
seg2=segtree([0]*m,lambda x,y:x+y,0)

vx=[(v[i],x[i]) for i in range(n)]
vx.sort()

ans=0
for vi,xi in vx:
  i=d[xi]
  ans+=seg1.query(0,i)*xi-seg2.query(0,i)
  seg1.update(i,1)
  seg2.update(i,xi)

print(ans)