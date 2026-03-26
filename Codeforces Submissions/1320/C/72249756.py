import sys
input = sys.stdin.readline

n,m,p=map(int,input().split())
W=[tuple(map(int,input().split())) for i in range(n)]
A=[tuple(map(int,input().split())) for i in range(m)]
M=[tuple(map(int,input().split())) for i in range(p)]

Q=[[] for i in range(10**6+1)]
for x,y,c in M:
    Q[x].append((c,y))

for x,c in W:
    Q[x-1].append((c,0))
 
seg_el=1<<((10**6+1).bit_length())
SEGMAX=[-2147483648]*seg_el

for x,y in A:
    SEGMAX[x-1]=max(SEGMAX[x-1],-y)

for i in range(seg_el-2,-1,-1):
    SEGMAX[i]=max(SEGMAX[i+1],SEGMAX[i])

SEGMAX=[-2147483648]*(seg_el)+SEGMAX

for i in range(seg_el-1,0,-1):
    SEGMAX[i]=max(SEGMAX[i*2],SEGMAX[(i*2)+1])

SEGADD=[0]*(2*seg_el)

def adds(l,r,x):
    L=l+seg_el
    R=r+seg_el

    while L<R:
        if L & 1:
            SEGADD[L]+=x
            L+=1

        if R & 1:
            R-=1
            SEGADD[R]+=x
        L>>=1
        R>>=1

    L=(l+seg_el)>>1
    R=(r+seg_el-1)>>1

    while L!=R:
        if L>R:
            SEGMAX[L]=max(SEGMAX[L*2]+SEGADD[L*2],SEGMAX[1+(L*2)]+SEGADD[1+(L*2)])
            L>>=1
        else:
            SEGMAX[R]=max(SEGMAX[R*2]+SEGADD[R*2],SEGMAX[1+(R*2)]+SEGADD[1+(R*2)])
            R>>=1

    while L!=0:
        SEGMAX[L]=max(SEGMAX[L*2]+SEGADD[L*2],SEGMAX[1+(L*2)]+SEGADD[1+(L*2)])
        L>>=1

ANS=-2147483648
for i in range(10**6+1):
    for c,y in Q[i]:
        if y==0:
            ANS=max(ANS,SEGMAX[1]-c)
        else:
            adds(y,seg_el,c)

print(ANS)
        

