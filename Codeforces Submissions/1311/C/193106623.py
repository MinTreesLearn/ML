for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    res = [0] * 26
    temp = [0] * (n + 1)
    p = list(map(int, input().split()))

    for num in p:
        temp[0] += 1
        temp[num] -= 1

    for i in range(1, n + 1):
        temp[i] += temp[i - 1]

    for i in range(n + 1):
        temp[i] += 1

    for i in range(n):
        idx = ord(s[i]) - 97
        res[idx] += temp[i]

    print(*res)