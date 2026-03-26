import sys
input=sys.stdin.readline
def validparenthesis(s,i,j):
    stack=[]
    for idx in range(i,j+1):
        if s[idx]=='(':stack.append(s[idx])
        else:
            if len(stack)==0:return False
            else:
                stack.pop()
    if len(stack)!=0:return False
    return True
from collections import Counter
n=int(input())
s=input().rstrip()
d=Counter(s)
if d[')']!=d['('] or n==1:print(-1)
else:
    i=c1=c2=0
    j=0
    ans=0
    while j<n:
        if s[j]=='(':c1+=1
        else:c2+=1
        if c1==c2:
            if not validparenthesis(s,i,j):
                ans+=(c1+c2)
            i=j+1
            j+=1
            c1=c2=0
        else:
            j+=1
    print(ans)