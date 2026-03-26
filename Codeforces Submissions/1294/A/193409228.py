t=int(input())
for k in range (t):
    unos=input()
    niz=[]
    for i in unos.split():
        broj=int(i)
        niz.append(broj)
    for i in range (3):
        for j in range (2):
            if niz[j]>niz[j+1]:
                pom=niz[j]
                niz[j]=niz[j+1]
                niz[j+1]=pom
    if (niz[0]+niz[1]+niz[2]+niz[3])%3==0:
        if niz[0]!=niz[1] and niz[1]!=niz[2] and abs(niz[0]-niz[2])+abs(niz[1]-niz[2])<=niz[3]:
                print("YES")
        elif niz[0]==niz[1] and niz[0]!=niz[2] and abs(niz[0]-niz[2])*2<=niz[3]:
            print("YES")
        elif niz[1]==niz[2] and niz[0]!=niz[1] and abs(niz[0]-niz[1])<=niz[3]:
            print("YES")
        elif niz[0]==niz[1] and niz[0]==niz[2]:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")