t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    if g >= n:
        print(n)
        continue
    # nice way to get ceiling 
    half = (n+1) // 2
    # multipler * chunk of g+b days + remainder good days
    remainder = half % g
    ans = (half//g) * (g+b) + remainder
    if remainder == 0: # remove bad days excess
        ans -= b
    print(max(ans, n))