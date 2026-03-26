#Это кстати моя самая первая решенная задача на кодфорсес раунде (13 попыток 1ч18мин)
import math

t = int(input())

for i in range(t):
    n, d = input().split()
    n = int(n)
    d = int(d)
    c = 0
    for x in range(n):
        if(x + math.ceil(d/(x + 1)) <= n):
            print("YES")
            c += 1
            break
    if c == 0:
        print("NO")