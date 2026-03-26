import sys
input = sys.stdin.readline

from itertools import accumulate

import random

t=int(input())


for testcases in range(t):
    n=int(input())
    S=[list(map(int,input().split())) for i in range(n)]

    compression_list=[]

    for l,r in S:
        compression_list.append(l)
        compression_list.append(r)

    compression_dict={a: ind for ind, a in enumerate(sorted(set(compression_list)))}

    for i in range(n):
        S[i][0]=compression_dict[S[i][0]]*2
        S[i][1]=compression_dict[S[i][1]]*2

    LEN=len(compression_dict)*2

    R=[0]*(LEN+1)

    for l,r in S:
        R[l]+=1
        R[r+1]-=1

    SR=list(accumulate(R))

    NOW=0

    for i in range(LEN):
        if SR[i]!=0 and SR[i+1]==0:
            NOW+=1

    ONECOUNT=[0]*(LEN+1)

    for i in range(1,LEN):
        if SR[i-1]!=1 and SR[i]==1:
            ONECOUNT[i]+=1

    SO=list(accumulate(ONECOUNT))
    SO.append(0)

    ANS=1

    for l,r in S:
        lr=0
        if SR[r]==1:
            lr-=1

        ANS=max(ANS,NOW+SO[r-1]-SO[l]+lr)


    print(ANS)
        
        
        

    

    

    

        
        
        
        

    
