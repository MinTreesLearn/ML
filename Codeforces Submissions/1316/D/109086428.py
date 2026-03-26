d4i=[0,-1,0,1]
d4j=[-1,0,1,0]
direction=['L','U','R','D']
back=['R','D','L','U']
 
def main():
    
    # Observations:
    #     if ri,cj==xi,yj, i,j is x
    #     if ri,cj==-1,-1, i,j is cycle:
    # Steps:
    #     Mark cycles and Xs
    #     DFS from all X only to nodes pointing to x
    #     Fill cycles by pointing to an adjacent cycle square
    #     Check that all cells are marked
    
    n=int(input())
    finalState=[[] for _ in range(n)] #[xi,yj]
    ans=[[None for _ in range(n+1)] for __ in range(n+1)]
    
    for i in range(n):
        temp=readIntArr()
        temp.append(-11) #adding extra col to avoid checking for out of grid
        temp.append(-11)
        for j in range(n+1):
            finalState[i].append([temp[2*j]-1,temp[2*j+1]-1]) #0-indexing
    finalState.append([None]*(n+1)) #adding extra row to avoid checking for out of grid
    
    endPoints=[]
    cyclePoints=set()
    for i in range(n):
        for j in range(n):
            x,y=finalState[i][j]
            if x==i and y==j:
                ans[i][j]='X'
                endPoints.append([x,y])
            elif x==-2: #due to 0-indexing
                ans[i][j]='c' #cycle
                cyclePoints.add((i,j))
    
    # multiLineArrayOfArraysPrint(finalState)
    # multiLineArrayOfArraysPrint(ans)
    
    for endX,endY in endPoints:
        stack=[[endX,endY]]
        while stack:
            i,j=stack.pop()
            for z in range(4):
                ii=i+d4i[z]
                jj=j+d4j[z]
                if ans[ii][jj]==None and finalState[ii][jj]==[endX,endY]:
                    ans[ii][jj]=back[z]
                    stack.append([ii,jj])
    
 
    
    # Fill Cycles (point each cycle point to another cycle point)
    for ci,cj in cyclePoints:
        for z in range(4):
            ii=ci+d4i[z]
            jj=cj+d4j[z]
            if (ii,jj) in cyclePoints:
                ans[ci][cj]=direction[z]
                break
    
    ok=True
    outcomes={'U','D','R','L','X'}
    for i in range(n):
        for j in range(n):
            if ans[i][j] not in outcomes:
                ok=False
    if ok:
        print('VALID')
        ans.pop()#remove extra row
        for i in range(n):
            ans[i].pop() #remove extra col
        multiLineArrayOfArraysPrint(ans)
    else:
        print('INVALID')
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
    print('\n'.join([''.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
 
inf=float('inf')
MOD=10**9+7
 
for _ in range(1):
    main()