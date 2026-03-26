tst = int(input())

vals = []

for i in range(0,tst):
  arr = a,b = [int(x) for x in input().split()]
  vals.append(arr)


for lst in vals:
  a = lst[0]
  b = lst[1]
  if a == b:
    print(0)
  elif a > b and (a-b)%2 == 0:
    print(1)
  elif a < b and (b-a)%2 != 0:
    print(1)
  else:
    print(2)