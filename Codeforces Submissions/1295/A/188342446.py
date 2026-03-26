t = int(input())
for _ in range(0, t):
    n = int(input())
    if n%2 == 0:
        a = n // 2
        n1 = "1" * a
    else:
        a = n // 2 - 1
        n1 = "7" + "1" * a
    if n%3 == 0 or n%3 == 2:
        a = n // 3
        b = n%3 // 2
        n2 = "7" * a + "1" * b
    elif n%3 == 1:
        a = n // 3 - 1
        n2 = "7" * a + "1" * 2
    n1 = int(n1)
    n2 = int(n2)
    print(max(n1, n2))