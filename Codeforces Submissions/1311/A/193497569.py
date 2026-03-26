t = int(input())

for i in range(t):
  a, b = (map(int, input().split()))

  if (a==b):
    print(0)
  elif (a< b and a%2 == b%2) or (a>b and a%2 != b%2):
    print(2)
  else:
    print(1)