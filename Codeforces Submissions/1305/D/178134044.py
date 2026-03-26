import math
from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

n = int(input())

edges = [-1]
for i in range(n):
  temp = []
  edges.append(temp)

for _ in range(n-1):

  u,v = map(int,input().split())

  edges[u].append(v)
  edges[v].append(u)

#print(edges)

def query(u,v):

  print("?",u,v,flush=True)

  return int(input())

  
leaves = []

for i in range(1,n+1):

  if len(edges[i]) == 1:

    leaves.append(i)

breaklol = False

#print(edges)
while len(leaves) > 1:



  while len(leaves) > 1:

    #if len(leaves) == 1:
      #new_leaves.append(leaves[0])
      #leaves.pop()
      #break
      
    q = query(leaves[-1],leaves[-2])
    if q == leaves[-1] or q == leaves[-2]:
      print("!",q,flush = True)
      breaklol = True
      break

    edges[leaves[-1]] = -1
    edges[leaves[-2]] = -1
    
    for i in range(1,len(edges)):

      if edges[i] != -1:

        if leaves[-1] in edges[i]:
          edges[i].remove(leaves[-1])
        if leaves[-2] in edges[i]:
          edges[i].remove(leaves[-2])

    leaves.pop()
    leaves.pop()

  if breaklol:
    break
    
  leaves = []
  for i in range(len(edges)):

    if edges[i] != -1 and len(edges[i]) == 1:
      leaves.append(i)

  #print(leaves)
      
ans = 0
cc = 0
for i in range(len(edges)):
  if edges[i] != -1:
    cc += 1
    ans = i
#print(edges)
if cc == 1:
  print("!",ans,flush = True)