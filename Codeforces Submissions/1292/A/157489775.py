n,q=map(int,input().split())
lava=[[0]*n for _ in[0,0]]
pairs=0
for _ in[0]*q:
 x,y=map(lambda s:int(s)-1,input().split())
 delta=1-2*(lava[x][y]==1)
 lava[x][y]=1-lava[x][y]
 for dy in range(-1,2):
  if 0<=y+dy<n and lava[1-x][y+dy]==1:pairs+=delta
 if not pairs:print('YES');continue
 print('NO')