import sys
input = sys.stdin.readline


for _ in range(int(input())):
    n = int(input())
    w = list(map(int, input().split()))
    s = set()
    c = 0
    for i in range(n):
        if w[i] == -1:
            if i > 0 and w[i-1] != -1:
                s.add(w[i-1])
            if i < n-1 and w[i+1] != -1:
                s.add(w[i+1])
        else:
            if i > 0 and w[i-1] != -1:
                if abs(w[i]-w[i-1]) > c:
                    c = abs(w[i] - w[i-1])
            if i < n-1 and w[i+1] != -1:
                if abs(w[i]-w[i+1]) > c:
                    c = abs(w[i]-w[i+1])
    if len(s) == 0:
        print(c, 0)
        continue
    a = max(s)
    b = min(s)
    x = (a+b)//2
    c = max(a-x, c)
    print(c, x)