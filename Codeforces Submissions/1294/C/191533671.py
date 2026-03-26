for _ in range(int(input())):
    i=2
    l=[]
    n=int(input())
    while i<=(n)**(1/2):
        if n%i==0:
            if i not in l:
                l.append(i)
                n=n/i
                if len(l)==2:
                    if n not in l and n>=2:
                        print("YES")
                        for i in l:
                            print(i,end=" ")
                        print(int(n))
                        break
                            
        i+=1
    else:
        print("NO")