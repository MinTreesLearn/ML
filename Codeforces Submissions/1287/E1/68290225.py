import sys
input = sys.stdin.readline

n=int(input())

ANS=[0]*n

print("?",1,n,flush=True)
S=["".join(sorted(input().strip())) for i in range(n*(n+1)//2)]

if n==1:
    print("!",S[0],flush=True)
    sys.exit()

print("?",2,n,flush=True)
T=["".join(sorted(input().strip())) for i in range(n*(n-1)//2)]

from collections import Counter

U=Counter(S)-Counter(T)

K=sorted(U.keys(),key=lambda x:len(x))

K=[Counter(k) for k in K]

ANS=[]

for i in range(n):
    x=list(K[i].keys())[0]
    ANS.append(x)

    for j in range(i+1,n):
        K[j][x]-=1
        if K[j][x]==0:
            del(K[j][x])

print("!","".join(ANS),flush=True)
