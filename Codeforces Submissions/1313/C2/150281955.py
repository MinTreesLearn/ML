import heapq
def findLess(n,array):
    stack=[]
    ans = []
    for x in range(n):
        if not stack:
            stack.append(x)
            ans.append(-1)
        else:
            while stack and array[stack[-1]]>array[x]:
                stack.pop()
            if not stack:
                ans.append(-1)
            else:
                ans.append(stack[-1])
            stack.append(x)
    return ans
# print(findLess(6,[1,3,4,3,5,4]))

def skyScrapers(n,array):
    ms = 0
    mi = 0
    for x in range(n):
        s = array[x]
        prev = array[x]
        next = array[x]
        for i in reversed(range(x)):
            s+= min(next,array[i])
            next = min(next,array[i])
        for j in range(x+1,n):
            s += min(prev,array[j])
            prev = min(prev,array[j])


        if s>ms:
            ms = s
            mi = x
    # print(mi)
    a,b=[],[]
    prev,next = array[mi],array[mi]
    for i in reversed(range(mi)):
        a.append( min(next, array[i]))
        next = min(next,array[i])
    for j in range(mi + 1, n):
        b.append(min(prev, array[j]))
        prev = min(prev,array[j])
    a.reverse()
    ans = a+[array[mi]]+b
    return ans


def skyScrapersOptimised(n,array):
    left = [array[0]]
    iarr = findLess(n,array)
    # print(iarr)
    for x in range(1,n):
        i = iarr[x]
        # print(i,x)
        if i==-1:
            left.append((x - i) * array[x])
        else:
            left.append(left[i]+(x-i)*array[x])
    # print(left)
    rarray = array[::-1]
    right = [rarray[0]]
    iarr = findLess(n, rarray)
    for x in range(1, n):
        i = iarr[x]
        # print(i,x)
        if i == -1:
            right.append((x - i) * rarray[x])
        else:
            right.append(right[i] + (x - i) * rarray[x])
    right.reverse()
    ms = 0
    mi = 0
    for x in range(n):
        s = left[x]+right[x]-array[x]
        if s>ms:
            ms =s
            mi = x

    # print(left,right)
    a, b = [], []
    prev, next = array[mi], array[mi]
    for i in reversed(range(mi)):
        a.append(min(next, array[i]))
        next = min(next, array[i])
    for j in range(mi + 1, n):
        b.append(min(prev, array[j]))
        prev = min(prev, array[j])
    a.reverse()
    ans = a + [array[mi]] + b
    return ans

import sys
input  = sys.stdin.readline
n = int(input())
l = list(map(int,input().split()))
ans = skyScrapersOptimised(n,l)

for x in ans:
    print(x,end=" ")
