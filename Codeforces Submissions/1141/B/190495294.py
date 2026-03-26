n=int(input())
lst=list(map(int,input().split()))
m=0
temp=0
for i in range(n):
    if (lst[i] ==1 and temp==0) or lst[i]==1 and lst[i-1]==1:
        temp+=1
    else:
        m=max(temp,m)
        temp=0
first=0
for ele in lst:
    if ele==0:
        break
    else:
        first+=1
second=0
for i in range(n-1,-1,-1):
    if lst[i]==0:
        break
    else:
        second+=1
tot=first+second
print(max(m,tot))