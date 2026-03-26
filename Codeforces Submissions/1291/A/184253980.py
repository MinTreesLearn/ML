for _ in range(int(input())):
    n = int(input())
    s = input()
    odd = []

    for i in range(n):
        if (int(s[i]) % 2 != 0):
            odd.append(s[i])

    if (len(odd) >= 2):
        print(''.join(odd[-2:]))
    else:
        print(-1)