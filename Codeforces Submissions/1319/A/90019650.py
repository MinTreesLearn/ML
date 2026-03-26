input()
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c1, c2 = 0, 0
for a, b in zip(a,b):
    if a != b:
        c1 += a
        c2 += b
print(c2//c1+1) if c1!=0 else print('-1')
