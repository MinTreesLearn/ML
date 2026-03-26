import sys
def f():
    n=int(input())
    arr=input()
    arr=arr.split(" ")
    arr=map(int,arr)
    arr=list(arr)
    count=0
    maxi=-sys.maxsize
    i=0
    while True:
        if i==(n*2)-1:
            break
        if i==n-1 and arr[i%n]==1:
            count=count+1
            i=i+1
        elif i==n-1 and arr[i%n]==0:
            maxi=max(maxi,count)
            break
        if arr[i%n]==1:
            count=count+1
            i=i+1
        elif arr[i%n]==0:
            maxi=max(maxi,count)
            count=0
            i=i+1
    return maxi
print(f())
