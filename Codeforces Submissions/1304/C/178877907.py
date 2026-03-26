from sys import stdin
input = stdin.readline

for case in range(int(input())):
    n, m = map(int, input().split())
    prev_min, prev_max, prev_t, ans = m, m, 0, True

    for line in range(n):
        t, l, h = map(int, input().split())

        theo_min, theo_max = prev_min - (t - prev_t), prev_max + (t - prev_t)

        if theo_min > h or theo_max < l: ans = False

        prev_min, prev_max, prev_t = max(l, theo_min), min(h, theo_max), t

    print('yEs') if ans else print('nO')

        

    
