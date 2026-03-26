n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
aon = 0
bon = 0
for i in range(n):
    if a[i] and not b[i]:
        aon+=1
    elif b[i] and not a[i]:
        bon+=1
if aon == 0:
    print(-1)
else:
    print((bon+aon)//aon)