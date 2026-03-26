for _ in range(int(input())):
    n = int(input())
    lis = list(map(int,input().split()))
    summ = 0
    oc=0
    for i in range(n):
        if lis[i]%2==0:
            oc=0
            print(1,i+1,sep = "\n")
            break
        else:
            oc+=1
        if oc==2:
            print(2)
            print(i,i+1)
            break
            
    else:
        print(-1)
            
