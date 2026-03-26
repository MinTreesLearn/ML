import sys
input = sys.stdin.readline
test = int(input())
for _ in range(test):
  s = input().rstrip()
  t = input().rstrip()
  n = len(s)
  m = len(t)
  ansls = []
  pos = [[1000 for i in range(26)] for j in range(n+2)]
  for i in range(n+1)[::-1]:
    if i < n:
      for j in range(26):
        pos[i][j] = pos[i+1][j]
    if i > 0:
      x = ord(s[i-1])-97
      pos[i][x] = i
  flg = 0
  for i in range(m):
    t1 = t[:i]
    t2 = t[i:]
    m1 = len(t1)
    m2 = len(t2)
    dp = [[1000 for i in range(m2+1)] for j in range(m1+1)]
    dp[0][0] = 0
    for j in range(m1+1):
      for k in range(m2+1):
        if j > 0 and dp[j-1][k] < 1000:
          t1x = ord(t1[j-1])-97
          dp[j][k] = min(dp[j][k],pos[dp[j-1][k]+1][t1x])
        if k > 0 and dp[j][k-1] < 1000:
          t2x = ord(t2[k-1])-97
          dp[j][k] = min(dp[j][k],pos[dp[j][k-1]+1][t2x])
    if dp[-1][-1] < 1000:
      flg = 1
      break
  if flg:
    print("YES")
  else:
    print("NO")