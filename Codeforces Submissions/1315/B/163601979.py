import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, p = map(int, input().split())
    s = input()[:-1]
    n = len(s)
    i = n-1
    c = 0
    x = {'A':a, 'B':b}
    while i > 0 and c + x[s[i-1]] <= p:
        c += x[s[i-1]]
        i -= 1
        while i > 0 and s[i-1] == s[i]:
            i -= 1
    print(i+1)