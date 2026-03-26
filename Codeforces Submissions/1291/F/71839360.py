import sys
def ask(s):
    print(s)
    sys.stdout.flush()
def solve():
    n, k = map(int, input().split())
    head = [True] * (n + 1)
    head[0] = False
    if k == 1:
        N = 2 * int(n / (k + 1))
    else:
        N = 2 * int(n / k)
    for i in range(1, N + 1):
        cl = (i - 1) * int((k + 1) / 2) + 1
        cr = i * int((k + 1) / 2)
        for j in range(1, i):
            l = (j - 1) * int((k + 1) / 2) + 1
            r = j * int((k + 1) / 2)
            ask("R")
            for shop in range(l, r + 1):
                ask("? " + str(shop))
                ans = input()
                if (ans == "Y"):
                    head[shop] = False
            for shop in range(cl, cr + 1):
                ask("? " + str(shop))
                ans = input()
                if (ans == "Y"):
                    head[shop] = False

    ans = 0
    ans = sum(map(int, head))
    ask("! " + str(ans))
solve()