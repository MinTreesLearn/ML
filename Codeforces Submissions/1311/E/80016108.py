t=int(input())
import math as m
def print_tree(l):
    t=[{'p':None, 'c':[]} for i in range(sum(l))]
    l2={i:[] for i in range(len(l))}
    j=0
    for i in range(sum(l)):
        l2[j].append(i+1)
        if len(l2[j])==l[j]:
            j+=1
    for i in range(1,len(l)):
        p=0
        for n in l2[i]:
            pi=l2[i-1][p]
            t[n-1]['p']=pi
            t[pi-1]['c'].append(n)
            if len(t[pi-1]['c'])==2:
                p+=1

    for i in range(1, len(t)):
        print(t[i]['p'], end=' ')
    print()
for _ in range(t):
    n, d = map(int, input().split())
    k=m.floor(m.log2(n))
    maxd=n*(n-1)//2
    mind=k*2**(k+1)-2**(k+1)+2+k*(n-2**(k+1)+1)
    if (d<mind) or (d>maxd):
        print("NO")
        continue
    l=[1 for i in range(n)]
    s=maxd
    lowest=1
    highest=n-1
    while (s>d):
        diff=s-d
        if (diff>highest-lowest):
            l[highest]-=1
            l[lowest]+=1
            s-=(highest-lowest)
            highest-=1
            if l[lowest-1]*2==l[lowest]:
                lowest+=1
        else:
            level=highest-diff
            l[level]+=1
            l[highest]-=1
            s-=diff
    print("YES")
    print_tree(l)
    
