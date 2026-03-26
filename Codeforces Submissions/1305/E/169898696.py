import math
n,m=map(int,input().split())
good=1
if n%2==0:
    if m>(n/2)*(n/2-1):
        print(-1)
        good=0
if n%2==1:
    if m>((n-1)/2)**2:
        print(-1)
        good=0
arr=[]
leftover=0
if good==1:
    if n==1:
        print(1)
    else:
        if int(math.sqrt(m))*(int(math.sqrt(m))+1)<=m:
            k=2*int(math.sqrt(m))+2
            leftover=m-int(math.sqrt(m))*(int(math.sqrt(m))+1)
        else:
            k=2*int(math.sqrt(m))+1
            leftover=m-int(math.sqrt(m))**2
        for i in range(k):
            arr.append(i+1)
        if leftover>0:
            arr.append(arr[k-1]+arr[k-2*leftover])
        zzz=(arr[len(arr)-1]+1)*2+1
        thing=arr[len(arr)-1]+1
        if n-len(arr)>0:
            add=n-len(arr)
            for i in range(add):
                arr.append(zzz)
                zzz+=thing
        print(*arr)
