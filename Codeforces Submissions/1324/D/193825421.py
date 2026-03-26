n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
for i in range(n):
    a[i]-=b[i]
a.sort()
count=0
lastindex=n
pos=0
for i in range(n):
    if a[i]>0:
        pos+=1
    count+=n-lastindex
    if lastindex==0:
        continue
    for j in range(lastindex-1,-1,-1):
        if a[i]+a[j]<=0:
            lastindex=j+1
            break
        if j==0 and a[i]+a[j]>0:
            lastindex=0
count+=n-lastindex
print((count-pos)//2)