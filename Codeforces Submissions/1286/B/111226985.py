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
    p=[-1 for _ in range(n+1)]
    c=[-1 for _ in range(n+1)]
    children=[[] for _ in range(n+1)]
    for i in range(1,n+1):
        pp,cc=readIntArr()
        p[i]=pp
        c[i]=cc
        if pp==0: #root
            root=i
        else:
            children[pp].append(i)
    
    @bootstrap
    def dfs(i): # return [subtree nodes]
        # print('node:{}'.format(i))
        if len(children[i])==0: # leaf, no children
            if c[i]>0:
                possible[0]=False
            val=1
            # "push" all larger values than val by 1
            for zz in range(1,n+1):
                if a[zz]>=val:
                    a[zz]+=1
            a[i]=val
            # print('leaf:{} a:{}'.format(i,a))
            yield [i]
        else:
            requiredCnts=c[i]
            childNodes=[]
            for child in children[i]:
                for node in (yield dfs(child)):
                    childNodes.append(node)
            if requiredCnts>len(childNodes):
                possible[0]=False
                yield [] # impossible
            childVals=[a[node] for node in childNodes]
            childVals.sort()
            if requiredCnts==0:
                val=1
            else:
                val=childVals[requiredCnts-1]+1
            # "push" all larger values than val by 1
            for zz in range(1,n+1):
                if a[zz]>=val:
                    a[zz]+=1
            
            # print('childVals before:{}'.format(childVals))
            childVals.append(val)
            childNodes.append(i)
            a[i]=val
            # print('marked i:{} val:{} childVals:{} a:{}'.format(i,val,childVals,a))
            yield childNodes
        yield []
    
    possible=[True]
    a=[-1 for _ in range(n+1)]
    dfs(root)
    # print('root:{}'.format(root))
    if possible[0]:
        print('YES')
        ans=a[1:]
        oneLineArrayPrint(ans)
    else:
        print('NO')
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
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
 
def makeArr(defaultVal,dimensionArr): # eg. makeArr(0,[n,m])
    dv=defaultVal;da=dimensionArr
    if len(da)==1:return [dv for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
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