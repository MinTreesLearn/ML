# for _ in range(int(input())):
#     n, m = map(int, input().split())
#     s = input()
#     arr = list(map(int, input().split(' ')))
#     arr = arr + [n]        
#     nums = [arr[i] - 1 for i in range(m + 1)]    
#     numToAlpha = {i:s[i] for i in range(n)}
#     dic = {chr(i + 97): 0 for i in range(26)}
#     sweep = [0]*(n + 1)        
#     for i in range(m + 1):
#       ind = nums[i]
#       sweep[0] += 1
#       sweep[ind + 1] -= 1
#     for i in range(1, n + 1):
#       sweep[i] += sweep[i - 1]
#     # print(sweep)
#     for i in range(n):
#       count = sweep[i]
#       alpha = numToAlpha[i]
#       dic[alpha] += count
#     print(*[i for i in dic.values()])

from collections import Counter
from itertools import accumulate


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    s = input()
    nums = list(map(int, input().split()))

    prefix = [0]*(n+1)

    for val in nums:
        prefix[0] += 1
        prefix[val] -= 1
    
    prefix = list(accumulate(prefix))
    ans = [0]*26

    
    for idx in range(n):
        ans[ord(s[idx]) - 97] += prefix[idx] + 1
    
   
    
    print(*ans)