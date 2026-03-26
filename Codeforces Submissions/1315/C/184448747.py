for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    lt = sorted(l)
    count = 0
    imp = False
    for k in range(2*n,0,-1):
        #print(lt[-1],k, "max et k")
        if lt[-1]<k:
            count+=1
        else: 
            count-=1
            #print("SALUT", count)
            lt.pop()
        #print("COUNT VAUT:", count)
        if count<0: imp = True; break
    if imp: print(-1)
    else:
        rep = []
        s = set([k+1 for k in range(2*n)])
        for e in l: s.remove(e)
        l2 = sorted(list(s))
        for k in range(2*n):
            cur = l[k//2]
            if not k%2: rep.append(cur)
            else:
                for e in l2:
                    if e>cur: m =e; break
                rep.append(m)
                l2.pop(l2.index(m))
        print(*rep)