for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    arr = list(map(int, input().split(' ')))
    arr = arr + [n]        
    nums = [arr[i] - 1 for i in range(m + 1)]    
    numToAlpha = {i:s[i] for i in range(n)}
    dic = {chr(i + 97): 0 for i in range(26)}
    sweep = [0]*(n + 1)
    # print(dic)
    # print(numToAlpha)
    for i in range(m + 1):
      ind = nums[i]
      sweep[0] += 1
      sweep[ind + 1] -= 1
    for i in range(1, n + 1):
      sweep[i] += sweep[i - 1]
    # print(sweep)
    for i in range(n):
      count = sweep[i]
      alpha = numToAlpha[i]
      dic[alpha] += count
    print(*[i for i in dic.values()])