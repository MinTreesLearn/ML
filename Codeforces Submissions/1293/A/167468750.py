#editorial solution
t = int(input())

for _ in range(t):
    n, s, k = map(int, input().split())
    a = set(map(int, input().split()))
    ans = 0

    for i in range(k+1):
        if (s-i >= 1 and not s-i in a) or (s+i <= n and not s+i in a):
            ans = i
            break

    print(ans)
    
