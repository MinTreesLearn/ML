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


q,x=map(int,input().split())
exist=[0]*(q+10)
now=list(range(x))
seg=segtree(list(range(q+10)),min,10**9)
for _ in range(q):
  y=int(input())%x
  z=now[y]
  if z>q:
    print(seg.tree[1])
    continue
  seg.update(z,10**9)
  now[y]+=x
  print(seg.tree[1])