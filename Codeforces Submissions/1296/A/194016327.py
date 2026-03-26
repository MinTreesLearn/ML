for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    sm=sum(l)
    even=0
    odd=0
    for j in l:
        if j%2==1:
            odd+=1
        else:
            even+=1
    if sm%2!=0 or (sm%2 == 0 and odd>0 and even>0):
         print("YES")
    else:
         print("NO")