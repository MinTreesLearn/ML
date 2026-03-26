n=int(input())
l1=[]
l2=[]
for i in range(n):
    l1.append(int(input()))
    l2.append([int(x) for x in input().split()])
for i in range(n):
    a=0
    b=0
    for j in l2[i]:
        if j%2==0:
            a=a+1
        else:
            b=b+1
    if min(a,b)==0:
        print("YES")
    else:
        print("NO")
print()