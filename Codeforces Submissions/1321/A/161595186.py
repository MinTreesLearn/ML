
n = int(input())

a = [int(l) for l in input().split()]
b = [int(l) for l in input().split()]

unfav = 0
fav = 0
imp = 1

for i in range(n):
    d = a[i] - b[i]
    if d == -1:
        unfav +=1
    elif d==1:
        fav +=1
        imp = 0

if imp == 0:
    if (unfav+1)%fav == 0:
        print((unfav+1)//fav)
    elif (unfav+1)%fav >0:
        print(((unfav + 1) // fav)+1)
else:
    print("-1")