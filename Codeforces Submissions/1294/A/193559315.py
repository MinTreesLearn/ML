t = int(input())

for i in range(t):
    a, b, c, n = map(int, input().split())
    total_coins = (a + b + c + n) // 3
    
    if (a + b + c + n) % 3 != 0 or total_coins < max(a, b, c):
        print("NO")
    else:
        print("YES")