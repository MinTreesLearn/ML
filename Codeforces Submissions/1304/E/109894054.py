from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc

def main():
    
    n=int(input())
    adj=[[] for _ in range(n+1)]
    for _ in range(n-1):
        u,v=readIntArr()
        adj[u].append(v)
        adj[v].append(u)
    
    
    # Note: For this question, root the tree at 1
    
    '''BINARY LIFTING LCA - Preprocess O(nlogn), find dist or LCA between 2 vertices in O(logn)'''
    @bootstrap
    def dfsPopulateAncestor(node,d): # NEEDS BOOTSTRAP
        m=len(path)
        b=1
        while m-b>=0:
            nodeAncestors[node].append(path[m-b])
            b*=2
        nodeDepths[node]=d
        path.append(node)
        for nex in adj[node]:
            if len(path)>=2 and nex==path[-2]: continue #parent
            yield dfsPopulateAncestor(nex,d+1)
        path.pop()
        yield None
    ## Needs adj as a global variable. adj[u]=[v1,v2, ... where there is an edge u-v]
    nodeDepths=[None for _ in range(n+1)]
    nodeAncestors=[[] for _ in range(n+1)] #[1 up, 2 up, 4 up, ...]
    root=1 ## To modify accordingly
    path=[]
    dfsPopulateAncestor(root,0)
    # print(nodeAncestors)
    @bootstrap
    def dfsEulerTour(node,p): #NEEDS BOOTSTRAP
        startTimes[node]=time[0]
        time[0]+=1
        for nex in adj[node]:
            if nex==p: continue #parent
            yield dfsEulerTour(nex,node)
        endTimes[node]=time[0]
        time[0]+=1
        yield None
    startTimes=[0 for _ in range(n+1)]
    endTimes=[0 for _ in range(n+1)]
    time=[0]
    dfsEulerTour(root,-1)
    def isAncestor(node,ancestorCandidate):
        ac=ancestorCandidate
        return startTimes[ac]<=startTimes[node] and endTimes[ac]>=endTimes[node]
    
    def getLCA(u,v):
        if isAncestor(u,v):
            return v
        elif isAncestor(v,u):
            return u
        else:
            # Find LCA
            ancestor=u
            while True:
                ancs=nodeAncestors[ancestor]
                m=len(ancs)
                assert m>0 # should not reach the root
                if isAncestor(v,ancs[0]): # found LCA
                    LCA=ancs[0]
                    break
                broken=False
                for i in range(m): # binary search up u's ancestor to find highest non-ancestor
                    if isAncestor(v,ancs[i]):
                        ancestor=ancs[i-1]
                        broken=True
                        break
                if broken==False:
                    ancestor=ancs[-1]
            return LCA
    
    def getDist(u,v):
        LCA=getLCA(u,v)
        return nodeDepths[u]+nodeDepths[v]-2*nodeDepths[LCA]
    
    q=int(input())
    allans=[]
    for _ in range(q):
        x,y,a,b,k=readIntArr()
        ans='NO'
        
        # Don't use the new path
        temp=k-getDist(a,b)
        if temp>=0 and temp%2==0:
            ans='YES'
        
        # Use the new path
        xy=getDist(x,y)
        # a-x-y-b, no cycle
        temp=k-(getDist(a,x)+getDist(b,y)+1)
        if temp>=0 and temp%2==0:
            ans='YES'
        # a-x-y-b, use 1 cycle
        temp=temp-(1+xy)
        if temp>=0 and temp%2==0:
            ans='YES'
        #a-y-x-b, no cycle
        temp=k-(getDist(a,y)+getDist(b,x)+1)
        if temp>=0 and temp%2==0:
            ans='YES'
        #a-y-x-b, use 1 cycle
        temp=temp-(1+xy)
        if temp>=0 and temp%2==0:
            ans='YES'
        
        allans.append(ans)
        
    multiLineArrayPrint(allans)
    
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