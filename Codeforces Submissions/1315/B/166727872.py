import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    a, b, p = map(int, input().split())
    s = input()

    s_len = len(s)

    result = 1
    f_used = ''
    for i in range(s_len - 1, 0, -1):
        if s[i - 1] == f_used:
            continue
        else:
            f_used = s[i - 1]
            if s[i - 1] == 'A':
                p -= a
            else:
                p -= b

            if p < 0:
                result = i + 1
                break

    print(result)