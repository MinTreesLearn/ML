n = int(input())
for i in range(n):
    n = int(input())
    sp = 0
    cur = 0
    while n >= 10:
        sp += n // 10 * 10
        cur = n // 10
        n = n % 10 + cur
    print(sp + n)