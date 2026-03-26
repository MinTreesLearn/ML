t = int(input())
for _ in range(t):
    n, g, b = map(int, input().split())
    half = (n+1) // 2 # nice way to get ceiling 
    # ans = multipler * block of g+b days + remainder g days
    remainder = half % g
    ans = (half//g) * (g+b) + remainder
    if remainder == 0: # remove bad days excess
        ans -= b
    print(max(ans, n))