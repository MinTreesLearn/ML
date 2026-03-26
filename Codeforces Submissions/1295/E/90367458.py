from operator import add

class LazySegmentTree():
    def __init__(self,n,init,merge=min,merge_unit=10**18,operate=add,operate_unit=0):
        self.merge=merge
        self.merge_unit=merge_unit
        self.operate=operate
        self.operate_unit=operate_unit

        self.n=(n-1).bit_length()
        self.data=[0 for i in range(1<<(self.n+1))]
        self.lazy=[0 for i in range(1<<(self.n+1))]
        for i in range(n):
            self.data[2**self.n+i]=init[i]
        for i in range(2**self.n-1,0,-1):
            self.data[i]=self.merge(self.data[2*i],self.data[2*i+1])

    def propagate_above(self,i):
        m=i.bit_length()-1
        for bit in range(m,0,-1):
            v=i>>bit
            add=self.lazy[v]
            self.lazy[v]=0
            self.data[2*v]=self.operate(self.data[2*v],add)
            self.data[2*v+1]=self.operate(self.data[2*v+1],add)
            self.lazy[2*v]=self.operate(self.lazy[2*v],add)
            self.lazy[2*v+1]=self.operate(self.lazy[2*v+1],add)


    def remerge_above(self,i):
        while i:
            i>>=1
            self.data[i]=self.operate(self.merge(self.data[2*i],self.data[2*i+1]),self.lazy[i])

    def update(self,l,r,x):
        l+=1<<self.n
        r+=1<<self.n
        l0=l//(l&-l)
        r0=r//(r&-r)-1
        while l<r:
            if l&1:
                self.data[l]=self.operate(self.data[l],x)
                self.lazy[l]=self.operate(self.lazy[l],x)
                l+=1
            if r&1:
                self.data[r-1]=self.operate(self.data[r-1],x)
                self.lazy[r-1]=self.operate(self.lazy[r-1],x)
            l>>=1
            r>>=1
        self.remerge_above(l0)
        self.remerge_above(r0)

    def query(self,l,r):
        l+=1<<self.n
        r+=1<<self.n
        l0=l//(l&-l)
        r0=r//(r&-r)-1
        self.propagate_above(l0)
        self.propagate_above(r0)
        res=self.merge_unit
        while l<r:
            if l&1:
                res=self.merge(res,self.data[l])
                l+=1
            if r&1:
                res=self.merge(res,self.data[r-1])
            l>>=1
            r>>=1
        return res

import sys,random

input=sys.stdin.buffer.readline
n=int(input())
#p=[i for i in range(n)]
#random.shuffle(p)
p=list(map(lambda x:int(x)-1,input().split()))
#a=[float(random.randint(1,10**5)) for i in range(n)]
a=list(map(float,input().split()))

pos=[0 for i in range(n+1)]
for i in range(n):
    pos[p[i]]=i
data=[0]*n
S=0
for i in range(n):
    S+=a[pos[i]]
    data[i]=S

init=[0]*n
for i in range(0,n):
    if p[i]>0:
        init[i]+=a[i]
    else:
        init[i]-=a[i]
    init[i]+=init[i-1]
LST=LazySegmentTree(n,init)

ans=a[0]
for i in range(n):
    tmp=data[i]+LST.query(0,n-1)
    ans=min(ans,tmp)
    LST.update(pos[i+1],n,-2*a[pos[i+1]])
print(int(ans))
