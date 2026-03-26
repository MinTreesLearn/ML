#! /bin/env python3

# perhaps... Life is full of puzzles

def main():
    n, q = map(int, input().split(' '))
    v = [[0 for i in range(n+5)] \
          for j in range(3)]
    # solve
    c = 0
    for _ in range(q):
        x, y = map(int, input().split(' '))
        s = v[x][y]
        cnt = 0
        l, r = max(1, y-1), min(n, y+1)
        for i in range(l, r+1):
            if v[3-x][i] == 1: cnt += 1
        c += cnt if s == 0 else -cnt
        v[x][y] ^= 1
        print("Yes" if c == 0 else "No")

main()