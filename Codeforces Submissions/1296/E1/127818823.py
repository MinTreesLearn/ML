def solve(s):
  res = []
  s2 = sorted(s)
  rightest = {}
  for i,c in enumerate(s2):
    rightest[c] = i
  for i,c in enumerate(s):
    done = [0,0]
    for j,c2 in enumerate(s):
      if j == i: break
      if rightest[c2] > rightest[c]:
        done[res[j]] = 1
    if done[1] == 0: res.append(1)
    elif done[0] == 0: res.append(0)
    else: return -1
  return res
    
T=1
for t in range(T):
  input()
  s = input()
  res = solve(s)
  if res == -1: print("NO")
  else:
    print("YES")
    print(*res,sep="")