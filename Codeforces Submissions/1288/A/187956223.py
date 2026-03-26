# Read the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
  # Read the number of days before the deadline and the number of days the program runs
  n, d = map(int, input().split())
  
  # Check if Adilbek can fit in n days
  if d <= n:
    print("YES")
  else:
    # Check if Adilbek can optimize the program
    low = 0
    high = n
    while low <= high:
      mid = (low + high) // 2
      if d <= (mid + 1) * (n - mid):
        high = mid - 1
      else:
        low = mid + 1
    if low <= n:
      print("YES")
    else:
      print("NO")
