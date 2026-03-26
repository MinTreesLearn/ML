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
    adj=[set() for _ in range(n+1)]
    for _ in range(n-1):
        u,v=readIntArr()
        adj[u].add(v)
        adj[v].add(u)
    
    visited=[False for _ in range(n+1)]
    leaves=[]
    for i in range(1,n+1):
        if len(adj[i])==1:
            leaves.append(i)
    
    @bootstrap
    def searchNRemove(u,w): #search for w and remove connection from w to neighbour. Also, visit all other nodes
        visited[u]=True
        for nex in adj[u]:
            if visited[nex]==False:
                if nex==w: #separate
                    adj[w].remove(u)
                    if len(adj[w])==1:
                        leaves.append(w)
                else:
                    yield searchNRemove(nex,w)
        yield None
    
    w=None
    while True:
        leaves2=[]
        while len(leaves2)<2 and leaves:
            leaf=leaves.pop()
            if visited[leaf]==False:
                leaves2.append(leaf)
        # print('leaves:{} leaves2:{}'.format(leaves,leaves2))
        if len(leaves)==0:
            if len(leaves2)==1: #last leaf is ans
                ans=leaves2[0]
                break
            elif len(leaves2)==2:
                ans=queryInteractive(*leaves2)
                break
            else: #len(leaves2)==1
                ans=w
                break
        w=queryInteractive(*leaves2)
        searchNRemove(leaves2[0],w)
        searchNRemove(leaves2[1],w)
        
    answerInteractive(ans)
    
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
 
main()