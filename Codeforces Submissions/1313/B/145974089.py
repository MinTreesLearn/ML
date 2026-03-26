t = int(input())
for i in range(t):
    n, x, y = list(map(int, input().split()))
    worst = min(n, x + y - 1)
    best = max(1, x + y - n + 1)
    print(min(best, worst), worst)

'''

'''
