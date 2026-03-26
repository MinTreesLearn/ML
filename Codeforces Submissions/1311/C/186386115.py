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
    cnt = Counter(s)
    ans = [0]*26

    
    for idx in range(n):
        ans[ord(s[idx]) - 97] += prefix[idx]
    
    for char in cnt:
        ans[ord(char) -97] += cnt[char]
    
    print(*ans)