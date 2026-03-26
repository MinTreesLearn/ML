import sys
 
q,x=map(int,sys.stdin.readline().split())
mex = 0
map=dict()
 
 
 
for _ in range(q):
  v=int(sys.stdin.readline())%x
  if v in map:
    map[v + x*map[v]] = 1
    map[v] += 1
  else:
    map[v] = 1
 
  while mex in map:
    mex += 1
  print(mex)