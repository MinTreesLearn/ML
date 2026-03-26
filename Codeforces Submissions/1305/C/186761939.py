import sys
input = sys.stdin.readline

n, m = map(int, input().split())
w = list(map(int, input().split()))
if n > m:
    print(0)
else:
    c = 1
    for i in range(n):
        for j in range(i+1, n):
            c = c * (abs(w[i]-w[j])) % m
            if c == 0:
                print(c)
                exit()
    print(c)
