for _ in range(int(input())):
  a, b, c, n = map(int, input().split(' '))
  coins = [a, b, c]
  coins.sort()
  coins_left = n - (coins[2] - coins[0]) - (coins[2] - coins[1])
  if coins_left >= 0 and coins_left % 3 == 0:
    print("YES")
  else:
    print("NO")