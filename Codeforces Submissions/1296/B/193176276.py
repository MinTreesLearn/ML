t = int(input())

for i in range(t):
    s = int(input())
    sum1 = 0

    while s > 9:
        x = s - (s % 10)
        s = s - x + x // 10
        sum1 += x
    sum1 += s
    print(sum1)