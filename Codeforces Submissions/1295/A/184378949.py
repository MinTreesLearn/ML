n = int(input())
for i in range(n):
    a = int(input())
    if a % 2 == 0:
        print("1" * (a // 2))
    else:
        print("7" + ("1" * ((a - 3) // 2)))
