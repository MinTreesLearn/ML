import sys
input = sys.stdin.readline
import math
import copy
import collections
from collections import deque

def solve(ans):
    print(len(ans))
    for ele in ans:
        print(ele[0],ele[1])

n,m,k = map(int,input().split())
count = 0
ans = []
if 4*n*m-2*n-2*m<k:
    print("NO")
elif n==1:
    print("YES")
    if m-1>=k:
        ans.append([k,'R'])
        solve(ans)
        quit()
    else:
        ans.append([m-1,'R'])
        k-=m-1
    ans.append([k,'L'])
    solve(ans)
elif m==1:
    print("YES")
    if n-1>=k:
        ans.append([k,'D'])
        solve(ans)
        quit()
    else:
        ans.append([n-1,'D'])
        k-=n-1
    ans.append([k,'U'])
    solve(ans)
else:
    print("YES")
    if n-1>=k:
        ans.append([k,'D'])
        solve(ans)
        quit()
    else:
        k-=n-1
        count+=1
        ans.append([n-1,'D'])
    row = n-1
    while row>0:
        if m-1>=k:
            ans.append([k,'R'])
            solve(ans)
            quit()
        else:
            k-=m-1
            count+=1
            ans.append([m-1,'R'])
        if m-1>=k:
            ans.append([k,'L'])
            solve(ans)
            quit()
        else:
            k-=m-1
            count+=1
            ans.append([m-1,'L'])
        count+=1
        ans.append([1,'U'])
        k-=1
        if k==0:
            solve(ans)
            quit()
        row-=1
    col = 0
    while col<m-1:
        col+=1
        count+=1
        ans.append([1,'R'])
        k-=1
        if k==0:
            solve(ans)
            quit()
        if n-1>=k:
            ans.append([k,'D'])
            solve(ans)
            quit()
        else:
            count+=1
            k-=n-1
            ans.append([n-1,'D'])
        if n-1>=k:
            ans.append([k,'U'])
            solve(ans)
            quit()
        else:
            count+=1
            k-=n-1
            ans.append([n-1,'U'])
    count+=1
    ans.append([k,'L'])
    solve(ans)

