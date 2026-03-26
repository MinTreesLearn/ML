from sys import stdin
input=lambda :stdin.readline()[:-1]

n=int(input())
p=list(map(lambda x:int(x)-1,input().split()))
a=list(map(int,input().split()))

def calc(mid):
  left=[0]*n
  c=0
  for i in range(n):
    if p[i]>mid:
      c+=a[i]
    left[i]=c
  
  right=[0]*n
  c=0
  for i in range(n-1,-1,-1):
    if p[i]<=mid:
      c+=a[i]
    right[i]=c
  
  res=10**18
  for i in range(n-1):
    res=min(res,left[i]+right[i+1])
  return res  
  
def ternary_search(L,R):
  # 準下凸関数の最小値
  while L+2<R:
    c1=L+(R-L)//3
    c2=R-(R-L)//3
    if calc(c1)<calc(c2):
      R=c2
    else:
      L=c1
  
  ans=10**18
  for i in range(L,R+1):
    ans=min(ans,calc(i))
  
  return ans


ans=ternary_search(-1,n)
print(min(ans,a[0],a[-1]))