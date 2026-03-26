
def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,s=input().split()
        n=int(n)
        
        s=s+'$'
        seq=[] # [isIncreasing,length]
        prev=None
        l=0
        for c in s:
            if c!=prev:
                if l>0: # not first
                    seq.append([prev=='<',l])
                l=1
            else:
                l+=1
            prev=c
        seq[0][1]+=1
        
        minLIS=[] # large to small
        curr=n
        # print(seq)
        startend=[] # [start, end]
        for i in range(len(seq)):
            l=seq[i][1]
            if seq[i][0]: # is increasing
                if i==0:
                    start=n-l+1
                    end=n
                    curr=start-1
                else:
                    start=startend[i-1][0]+1
                    end=start+l-1
            else: # is decreasing
                if i+1<len(seq):
                    start=curr-seq[i+1][1]
                    end=start-l+1
                    curr=end-1
                else:
                    start=l
                    end=1
            startend.append([start,end])
        # print(seq)
        # print(startend)
        for start,end in startend:
            if start<=end:
                for v in range(start,end+1):
                    minLIS.append(v)
            else:
                for v in range(start,end-1,-1):
                    minLIS.append(v)
            # print('start:{} end:{} minLIS:{}'.format(start,end,minLIS))
        
        maxLIS=[] # small to large
        startend=[] # [start,end]
        curr=1
        for i in range(len(seq)):
            l=seq[i][1]
            if seq[i][0]: # is increasing
                if i+1<len(seq):
                    start=curr+seq[i+1][1]
                else:
                    start=curr
                end=start+l-1
                curr=end+1
            else: # is decreasing
                if i-1>=0:
                    start=startend[i-1][0]-1
                else:
                    start=l
                    curr=start+1
                end=start-l+1
            startend.append([start,end])
        # print(seq)
        # print(startend)
        for start,end in startend:
            if start<=end:
                for v in range(start,end+1):
                    maxLIS.append(v)
            else:
                for v in range(start,end-1,-1):
                    maxLIS.append(v)
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