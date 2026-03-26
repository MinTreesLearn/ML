from sys import stdin
input=lambda :stdin.readline()[:-1]

h,w=map(int,input().split())
mat=[]
for i in range(h):
  mat.append(list(map(lambda x:int(x)-1,input().split())))

def calc(col):
  ok=[0]*h
  for i in range(h):
    if col[i]!=-1:
      ok[(i-col[i])%h]+=1
  res=h
  for i in range(h):
    res=min(res,i+h-ok[i])
  return res

ans=0
for i in range(w):
  col=[]
  for j in range(h):
    if mat[j][i]%w==i and mat[j][i]<h*w:
      col.append(mat[j][i]//w)
    else:
      col.append(-1)
  ans+=calc(col)

print(ans)