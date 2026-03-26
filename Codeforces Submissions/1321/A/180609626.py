
n = int(input())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
s = 0
r = 0
for i in range(n):
    if(l1[i]==1  and l2[i]==0):
        s = s +1 
    elif(l1[i]==0  and l2[i]==1):
        r = r +1 



if(s==r):
    if(s==0):
        print(-1)
    else:
        print(2)
elif(s>r):
    print(1)
else:
    if(s!=0):
        c = r//s +1 
        print(c)
    else:
        print(-1)