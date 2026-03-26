for t in range(int(input())):
  arr = list(map(int,input().strip().split()))[:2]
  if(arr[0] % arr[1]):
    print("NO")
  else:
    print("YES")