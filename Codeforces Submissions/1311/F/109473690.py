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
    
    n=int(input())
    xes=readIntArr()
    ves=readIntArr()
    
    #perform coordinate compression on xes. Compressed values shall be the indexes of segment tree
    xes2=list(sorted(xes)) #xes2[compressed]=x
    xTox2Map=dict()
    for i,x in enumerate(xes2):
        xTox2Map[x]=i #xTox2Map[x]=i
    
    arr=[] #[original x, compressed x, v]
    for i in range(n):
        arr.append([xes[i],xTox2Map[xes[i]],ves[i]])
    arr.sort(key=lambda x:(x[2],x[0])) #sort by v asc, then position asc
    
    segArray=[0 for _ in range(n)] #index shall be compressed x, value is actual x
    st=getSumSegTree(segArray) #for sum of xes
    stCnts=getSumSegTree(segArray.copy()) #for counts
    
    # print(arr)
    ans=0
    for originalX,compressedX,v in arr:
        smallerSums=st.query(0,compressedX)
        smallerCounts=stCnts.query(0,compressedX)
        ans+=originalX*smallerCounts-smallerSums
        
        st.updateTreeNode(compressedX,originalX) #update the tree
        stCnts.updateTreeNode(compressedX,1)
        # print(ans)
    print(ans)
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# import sys
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
 
inf=float('inf')
MOD=10**9+7
 
main()