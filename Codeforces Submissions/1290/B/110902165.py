def charToInt(c): #'a'->0
    return ord(c)-ord('a')

def main():
    
    s=input()
    n=len(s)
    arr=[charToInt(c) for c in s]
    
    p=makeArr(0,n,26)
    for i in range(n):
        p[i][arr[i]]+=1
    for i in range(1,n):
        for j in range(26):
            p[i][j]+=p[i-1][j]
    
    def getCnts(char,l,r):
        if l==0: return p[r][char]
        else: return p[r][char]-p[l-1][char]
    
    allans=[]
    q=int(input())
    for _ in range(q):
        l,r=readIntArr()
        l-=1
        r-=1
        charTypeCnt=0
        for j in range(26):
            if getCnts(j,l,r)>0:
                charTypeCnt+=1
        if l==r:
            allans.append('Yes')
        elif charTypeCnt==1:
            allans.append('No')
        elif charTypeCnt==2:
            if arr[l]==arr[r]:
                allans.append('No')
            else:
                allans.append('Yes') # swap both sides
        else: # more than 2 types
            allans.append('Yes')
    multiLineArrayPrint(allans)
    
    return
    
import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
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