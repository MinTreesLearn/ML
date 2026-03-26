def PROBLEM():
    n,m=map(int,input().split())
    T=[]
    for _ in range(n):
        T.append(input())
    S=''
    i=0
    Nb=1
    while T!=[]:
        P=RecherchePosPali(T,n,T[i])
        if P!=-1:
            S=T[i]+S+T[P]
            T.remove(T[P])
            T.remove(T[i])
            n-=2
        elif Nb and S[:len(S)//2]+T[i]+S[len(S)//2:]==(S[:len(S)//2]+T[i]+S[len(S)//2:])[::-1]:
            S=S[:len(S)//2]+T[i]+S[len(S)//2:]
            T.remove(T[i])
            n-=1
            Nb=0
        else:
            T.remove(T[i])
            n-=1
    print(len(S))
    print(S)
def RecherchePosPali(T,n,S):
    P=-1
    i=1
    while P==-1 and i<n:
        if S==T[i][::-1]:
            P=i
        else:
            i+=1
    return P
    
PROBLEM()
    
