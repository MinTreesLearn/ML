t=int(input())
for i in range(t):
    n=int(input())
    even=odd=0
    l=list(map(int,input().split()))
    for i in l:
        if i%2==0:
            even+=1
        else:
            odd+=1
    if sum(l)%2!=0:
        print("YES")
    else:
        if even!=0 and odd!=0:
            print("YES")
        else:
            print("NO")
            