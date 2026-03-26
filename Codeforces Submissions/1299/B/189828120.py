import math
import queue


# -------- info --------

# https://codeforces.com/profile/Wolxy

# -------- solve --------

def solve() -> None:
    n = int(input())
    if n % 2 != 0:
        print('NO')
        return

    ls = []
    for _ in range(n):
        ls.append(tuple(map(int, input().split(' '))))
    ox, oy = (ls[0][0] + ls[n // 2][0]) / 2, (ls[0][1] + ls[n // 2][1]) / 2
    for i in range(n // 2):
        if ((ls[i][0] + ls[n // 2 + i][0]) / 2, (ls[i][1] + ls[n // 2 + i][1]) / 2) != (ox, oy):
            print('NO')
            return
    print('YES')


# -------- main --------


T = 1
# T = int(input())
for _ in range(T):
    solve()
