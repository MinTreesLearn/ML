
def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,s=input().split()
        n=int(n)
        
        #for maxLIS, put small to large.
        decreasesInARow=[0 for _ in range(n-1)]
        for i in range(n-2,-1,-1):
            if s[i]=='>':
                decreasesInARow[i]+=1
                if i+1<n-1:
                    decreasesInARow[i]+=decreasesInARow[i+1]
        maxLIS=[]
        currMin=1
        i=0
        while i<n-1:
            l=decreasesInARow[i]+1
            j=currMin+l-1
            currMin=j+1
            i+=l
            for k in range(l):
                maxLIS.append(j)
                j-=1
        if i==n-1:
            maxLIS.append(currMin)
        
        # for minLIS, put large to small. can do something very similar to maxLIS
        # in s, flip the signs and run the same thing. then for final ans,
        # change to n+1-minLIST[i]
        s2=[]
        for x in s:
            if x=='<':s2.append('>')
            else:s2.append('<')
        s=s2
        decreasesInARow=[0 for _ in range(n-1)]
        for i in range(n-2,-1,-1):
            if s[i]=='>':
                decreasesInARow[i]+=1
                if i+1<n-1:
                    decreasesInARow[i]+=decreasesInARow[i+1]
        minLIS=[]
        currMin=1
        i=0
        while i<n-1:
            l=decreasesInARow[i]+1
            j=currMin+l-1
            currMin=j+1
            i+=l
            for k in range(l):
                minLIS.append(j)
                j-=1
        if i==n-1:
            minLIS.append(currMin)
        for i,x in enumerate(minLIS):
            minLIS[i]=n+1-x
            
        allans.append(minLIS)
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