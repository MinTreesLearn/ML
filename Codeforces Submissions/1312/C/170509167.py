for _ in range(int(input())):
    n,k=map(int,input().split())
    L=input().split()
    dict={}
    for i in range(n):
        a=int(L[i])
        if a==0:
            continue
        else:
            i=0
            breakage=False
            while a!=0:
                if a%k==1:
                    try:
                        dict[i]
                        breakage=True
                        break
                    except:
                        dict[i]=1
                elif a%k!=0:
                    breakage=True
                    break
                a=a//k
                i+=1
        if breakage:
            print("NO")
            break
    else:
        print("YES")