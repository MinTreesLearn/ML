class SegmentTree():
    def __init__(self,arr,func,initialRes=0):
        self.f=func
        self.N=len(arr) 
        self.tree=[0 for _ in range(4*self.N)]
        self.initialRes=initialRes
        for i in range(self.N):
            self.tree[self.N+i]=arr[i]
        for i in range(self.N-1,0,-1):
            self.tree[i]=self.f(self.tree[i<<1],self.tree[i<<1|1])
    def updateTreeNode(self,idx,value): #update value at arr[idx]
        self.tree[idx+self.N]=value
        idx+=self.N
        i=idx
        while i>1:
            self.tree[i>>1]=self.f(self.tree[i],self.tree[i^1])
            i>>=1
    def query(self,l,r): #get sum (or whatever function) on interval [l,r] inclusive
        r+=1
        res=self.initialRes
        l+=self.N
        r+=self.N
        while l<r:
            if l&1:
                res=self.f(res,self.tree[l])
                l+=1
            if r&1:
                r-=1
                res=self.f(res,self.tree[r])
            l>>=1
            r>>=1
        return res
def getMaxSegTree(arr):
    return SegmentTree(arr,lambda a,b:max(a,b),initialRes=-float('inf'))
def getMinSegTree(arr):
    return SegmentTree(arr,lambda a,b:min(a,b),initialRes=float('inf'))
def getSumSegTree(arr):
    return SegmentTree(arr,lambda a,b:a+b,initialRes=0)

def main():
    
    n,m=readIntArr()
    a=readIntArr()
    
    indexes=[-1 for _ in range(n+1)] #indexes[p]=current index
    #start with all indexes shifted by m positions. Then move them to the left each time.
    j=m
    for i in range(1,n+1):
        indexes[i]=j
        j+=1
    
    gaps=[1]*m+[0]*n #intially all the gaps are on the left
    st=getSumSegTree(gaps)
    
    mins=[inf for _ in range(n+1)] # 0-indexed for indexes
    maxes=[-inf for _ in range(n+1)] # 0-indexed
    for i in range(1,n+1):
        mins[i]=indexes[i]-m
        maxes[i]=indexes[i]-m
    
    left=m
    for p in a:
        mins[p]=0
        idx=indexes[p]
        gapCnts=st.query(0,idx)
        right=idx-gapCnts
        maxes[p]=max(maxes[p],right)
        # move p to left-1
        st.updateTreeNode(idx,1) # create gap
        st.updateTreeNode(left-1,0) #remove gap
        indexes[p]=left-1
        
        left-=1
    
    # final positions
    for p in range(1,n+1):
        idx=indexes[p]
        gapCnts=st.query(0,idx)
        right=idx-gapCnts
        maxes[p]=max(maxes[p],right)
    
    allans=[]
    for p in range(1,n+1):
        allans.append([mins[p]+1,maxes[p]+1])
    multiLineArrayOfArraysPrint(allans)
        
    
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(*args):
    """
    *args : (default value, dimension 1, dimension 2,...)
    
    Returns : arr[dim1][dim2]... filled with default value
    """
    assert len(args) >= 2, "makeArr args should be (default value, dimension 1, dimension 2,..."
    if len(args) == 2:
        return [args[0] for _ in range(args[1])]
    else:
        return [makeArr(args[0],*args[2:]) for _ in range(args[1])]
 
def queryInteractive(x,y):
    print('? {} {}'.format(x,y))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7
 
for _abc in range(1):
    main()