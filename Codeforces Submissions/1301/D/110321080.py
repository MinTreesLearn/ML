def loopRight(path):
    path.append('DUR')
def loopLeft(path):
    path.append('DUL')
def straightRight(path,n):
    path.append('R'*(n-1))
def straightLeft(path,n):
    path.append('L'*(n-1))

def main():
    
    n,m,k=readIntArr()
    if k>4*n*m-2*n-2*m:
        print('NO')
        return
    
    # 2 steps per row going down, 2 steps per row going up.
    # worse case of 2 * 2 * 500 steps = 2000 steps << 3000 steps
    
    temp=n
    n=m
    m=temp # swap because i mixed up rows and columns
    
    path=[] # [combo, counts]
    # fill in all characters first...
    for row in range(m-1):
        if row%2==0:
            # for col in range(n-1):
            #     loopRight(path)
            path.append(['DUR',n-1])
        else:
            # for col in range(n-1):
            #     loopLeft(path)
            path.append(['DUL',n-1])
        path.append(['D',1])
    if m%2==1:
        # straightRight(path,n)
        path.append(['R',n-1])
    else:
        # straightLeft(path,n)
        path.append(['L',n-1])
    for row in range(m-1,-1,-1):
        if row%2==0:
            # straightLeft(path,n)
            path.append(['L',n-1])
        else:
            # straightRight(path,n)
            path.append(['R',n-1])
        if row>0:
            path.append(['U',1])

    # print(path)
    ans=[]
    l=0
    for combo,counts in path:
        # print('combo:{} cnts:{} l:{}'.format(combo,counts,l))
        z=len(combo)
        if l+z*counts<=k:
            ans.append([counts,combo])
            l+=z*counts
        else:
            i=0
            while l+z*(i+1)<=k:
                i+=1
            assert i<=counts
            if i>0:
                ans.append([i,combo])
                l+=z*i
            while l<k: # add 1 letter by 1 letter
                for c in combo:
                    ans.append([1,c])
                    l+=1
                    if l==k:
                        break
        if l==k:
            break
    # in case n==1 or m==1, there may be 0 counts. remove all 0 counts.
    ans2=[]
    for cnt,combo in ans:
        if cnt>0:
            ans2.append([cnt,combo])
    ans=ans2
    
    print('YES')
    print(len(ans))
    multiLineArrayOfArraysPrint(ans)
    
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