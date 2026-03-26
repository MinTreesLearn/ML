import sys
input = sys.stdin.readline

n=int(input())
t=input().strip()
q=int(input())

ZEROS=[0]*n
ZERO_ONE=[]
ONECOUNT=[0]*n

ind=0
count=0
for i in range(n):
    ZEROS[i]=ind
    if t[i]=="0":
        ind+=1
        ONECOUNT[i]=count%2
        ZERO_ONE.append(count%2)
        count=0
    else:
        count+=1
        ONECOUNT[i]=count

ZEROS.append(ind)
    
S=ZERO_ONE

LEN=len(S)

p=2
import random
mod=random.randint(10**8,10**9)*2+1
mod2=random.randint(10**8,10**9)*2+1
mod3=random.randint(10**8,10**9)*2+1
mod4=random.randint(10**8,10**9)*2+1

TABLE=[0]
TABLE2=[0]
TABLE3=[0]
TABLE4=[0]

for i in range(LEN):
    TABLE.append(p*TABLE[-1]%mod+S[i]%mod) # テーブルを埋める
    TABLE2.append(p*TABLE2[-1]%mod2+S[i]%mod2) # テーブルを埋める
    TABLE3.append(p*TABLE3[-1]%mod3+S[i]%mod2) # テーブルを埋める
    TABLE4.append(p*TABLE4[-1]%mod4+S[i]%mod4) # テーブルを埋める

def hash_ij(i,j): # [i,j)のハッシュ値を求める
    return (TABLE[j]-TABLE[i]*pow(p,j-i,mod))%mod

def hash_ij2(i,j): # [i,j)のハッシュ値を求める
    return (TABLE2[j]-TABLE2[i]*pow(p,j-i,mod2))%mod2

def hash_ij3(i,j): # [i,j)のハッシュ値を求める
    return (TABLE3[j]-TABLE3[i]*pow(p,j-i,mod3))%mod3

def hash_ij4(i,j): # [i,j)のハッシュ値を求める
    return (TABLE4[j]-TABLE4[i]*pow(p,j-i,mod4))%mod4


def zcount(l,LEN):
    return ZEROS[l+LEN]-ZEROS[l]

def first_check(l,LEN):
    if t[l]=="0":
        return 0
    else:
        return (ZERO_ONE[ZEROS[l]]-ONECOUNT[l]+1)%2

def equalcheck(l1,l2,LEN):
    f1,f2=ZEROS[l1]+1,ZEROS[l2]+1
    
    if l1+LEN-1=="0":
        la1=ZEROS[l1+LEN]
    else:
        la1=ZEROS[l1+LEN]-1

    if l2+LEN-1=="0":
        la2=ZEROS[l2+LEN]
    else:
        la2=ZEROS[l2+LEN]-1

    if hash_ij(f1,la1+1)==hash_ij(f2,la2+1) and hash_ij2(f1,la1+1)==hash_ij2(f2,la2+1) and hash_ij3(f1,la1+1)==hash_ij3(f2,la2+1) and hash_ij4(f1,la1+1)==hash_ij4(f2,la2+1):
        return "Yes"
    else:
        return "No"

for queries in range(q):
    l1,l2,LEN=map(int,input().split())
    l1-=1
    l2-=1

    #print(l1,l2,LEN)
    
    if zcount(l1,LEN)!=zcount(l2,LEN):
        print("No")
        continue

    if zcount(l1,LEN)==0:
        print("Yes")
        continue

    if first_check(l1,LEN)!=first_check(l2,LEN):
        print("No")
        continue
    
    if zcount(l1,LEN)==1:
        print("Yes")
        continue   

    print(equalcheck(l1,l2,LEN))

    

    
    
