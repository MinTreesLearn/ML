
def main():
    
    n=int(input())
    adj=[set() for _ in range(n+1)]
    for _ in range(n-1):
        u,v=readIntArr()
        adj[u].add(v)
        adj[v].add(u)
    
    leaves=set()
    for i in range(1,n+1):
        if len(adj[i])==1:
            leaves.add(i)
    
    #Iteratively remove leaves. Each pair of leaves will eliminate 2 nodes.
    while True:
        u=leaves.pop()
        v=leaves.pop()
        u2=next(iter(adj[u]))
        v2=next(iter(adj[v]))
        # print('u:{} v:{} u2:{} v2:{} adj:{};'.format(u,v,u2,v2,adj))
        adj[u2].remove(u)
        adj[v2].remove(v)
        if len(adj[u2])==1:leaves.add(u2)
        if len(adj[v2])==1:leaves.add(v2)
        w=queryInteractive(u,v)
        if u==w or v==w or len(leaves)==0:
            answerInteractive(w)
            break
    
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