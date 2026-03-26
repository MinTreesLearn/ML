import sys
input = sys.stdin.readline

t=int(input())

for testcases in range(t):
    n=int(input())
    S=[tuple(map(int,input().split())) for i in range(n)]

    S.sort()
    S.append((1<<31,1<<31))

    seg_el=1<<(n.bit_length())
    SEG=[1<<30]*(2*seg_el)

    def update(n,x,seg_el):
        i=n+seg_el
        SEG[i]=x
        i>>=1
        
        while i!=0:
            SEG[i]=min(SEG[i*2],SEG[i*2+1])
            i>>=1
            
    def getvalues(l,r):
        L=l+seg_el
        R=r+seg_el
        ANS=1<<30

        while L<R:
            if L & 1:
                ANS=min(ANS , SEG[L])
                L+=1

            if R & 1:
                R-=1
                ANS=min(ANS , SEG[R])
            L>>=1
            R>>=1

        return ANS

    LEFT=[0]*n
    MAX=-1<<31
    MAXLIST=[]

    for i in range(n):
        if MAX<S[i][0]:
            LEFT[i]=LEFT[i-1]+1
        else:
            LEFT[i]=LEFT[i-1]
        MAX=max(MAX,S[i][1])
        MAXLIST.append(MAX)

    RIGHT=[0]*(n+1)
    RIGHT[n-1]=1
    update(n-1,1,seg_el)
    update(n,0,seg_el)
    import bisect
    for i in range(n-2,-1,-1):
        l,r=S[i]
        if l==S[i+1][0]:
            RIGHT[i]=RIGHT[i+1]
        else:           
            x=bisect.bisect_left(S,(r,-1<<31))
            if x<i+1:
                x=i+1
            if r==S[x][0]:
                RIGHT[i]=getvalues(i+1,x+1)
            else:
                RIGHT[i]=min(getvalues(i+1,x),RIGHT[x]+1)
                
        update(i,RIGHT[i],seg_el)

    #print(S)
    #print(LEFT)
    #print(RIGHT)

    ANS=max(RIGHT[1],LEFT[-2])

    for i in range(1,n-1):
        if S[i][0]==S[i+1][0] or (S[i][0]!=S[i-1][0] and S[i][1]<=MAXLIST[i-1]):
            continue
        x=bisect.bisect_left(S,(MAXLIST[i-1],-1<<31))
        if x<i+1:
            x=i+1

        #print(S[i][0],S[i][1],x)
        if MAXLIST[i-1]==S[x][0]:
            ANS=max(ANS,LEFT[i-1]+getvalues(i+1,x+1)-1)

        else:
            ANS=max(ANS,LEFT[i-1]+min(getvalues(i+1,x)-1,RIGHT[x]))

    print(ANS)
    
