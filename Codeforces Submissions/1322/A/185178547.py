n = int(input())
a = list(input())
s1 = 0
t = 0
for i in range(n):
    if a[i] == "(": 
        s1 += 1
    else:
        s1 -= 1
        if s1 < 0:
            t += 2
if s1 != 0:
    print(-1)
else:
    print(t)