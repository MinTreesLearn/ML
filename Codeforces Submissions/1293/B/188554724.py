import math


# -------- info --------

# https://codeforces.com/profile/Wolxy

# -------- solve --------

def solve() -> None:
    n = int(input())
    print(sum(1 / i for i in range(1, n + 1)))

# -------- main --------


T = 1
# T = int(input())
for _ in range(T):
    solve()
