
n,m,p = tuple(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))

i =0
while i<n:
    if a[i]%p != 0:
        break
    i+=1

j =0
while j<m:
    if b[j]%p != 0:
        break
    j+=1

print(i+j)
