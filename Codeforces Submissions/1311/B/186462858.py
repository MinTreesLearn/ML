for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = list(map(int, input().split(' ')))    
    nums = list(map(int, input().split(' ')))        
    while True:
      flag = False
      for i in range(m):
        if arr[nums[i] - 1] > arr[nums[i]]:
          arr[nums[i] - 1], arr[nums[i]] = arr[nums[i]], arr[nums[i] - 1]
          flag = True
      if not flag: break            

    ans = 'YES'    
    for i in range(len(arr) - 1):
      if arr[i] > arr[i + 1]:        
        ans = 'NO'        
        break
    print(ans)
    