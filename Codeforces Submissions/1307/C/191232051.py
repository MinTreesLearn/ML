#! /bin/env python3

# please follow ATshayu

def main():
    N = int(1e5) + 5
    A = 26 + 5
    s = '#' + input()
    # solve
    n = len(s) - 1
    c = [[0 for i in range(A)] for j in range(N)]
    for i in range(n-1, 0, -1):
        for j in range(A): c[i][j] = c[i+1][j]
        val = ord(s[i+1]) - 97
        c[i][val] += 1
    ATshayu = 0
    for i in range(A):
        for j in range(-1, A):
            x = 0
            if j < 0:
                for k in range(1, n+1): 
                    if s[k] == chr(i+97): x += 1
            else:
                for k in range(1, n):
                    if s[k] == chr(i+97): x += c[k][j]
            ATshayu = max(ATshayu, x)
    print(ATshayu)

main()