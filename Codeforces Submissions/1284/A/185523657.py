n,m=[int(i) for i in input().split()]
s=[z for z in input().split()]
t=[z for z in input().split()]
q=int(input())
for j in range(q):
    y=int(input())
    y1=(y%n)-1
    y2=(y%m)-1
    print(s[y1]+t[y2])