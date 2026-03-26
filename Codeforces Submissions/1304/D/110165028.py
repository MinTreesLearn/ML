def reverse(arr,i,j):
    while i<j:
        temp=arr[i]
        arr[i]=arr[j]
        arr[j]=temp
        i+=1
        j-=1
    return None

def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,s=input().split()
        n=int(n)
        
        minLIS=list(range(n,0,-1))
        i=0
        while i<n-1:
            j=i
            while j<n-1 and s[j]=='<':
                j+=1
            reverse(minLIS,i,j)
            # print(i,j)
            i=j+1
        allans.append(minLIS)
        
        maxLIS=list(range(1,n+1))
        i=0
        while i<n-1:
            j=i
            while j<n-1 and s[j]=='>':
                j+=1
            reverse(maxLIS,i,j)
            # print(i,j)
            i=j+1
        allans.append(maxLIS)
    
    multiLineArrayOfArraysPrint(allans)
        
    
    return
    
# import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
import sys
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