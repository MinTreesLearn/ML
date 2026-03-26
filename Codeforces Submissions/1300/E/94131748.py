import sys
input = lambda:sys.stdin.readline().rstrip()
def main():
  n=int(input())
  a=list(map(int,input().split()))
  d=n+1
  b=[a[0]*d+1]
  for i in range(1,n):
    if b[-1]//d==a[i]:
      b[-1]+=1
    else:
      b.append(a[i]*d+1)
  bx,bi=divmod(b[0],d)
  bx*=bi
  s=[bx*d+bi]
  for ii in range(1,len(b)):
    cx,ci=divmod(b[ii],d)
    cx*=ci
    s.append(cx*d+ci)
    bx,bi=divmod(s[-2],d)
    cx,ci=divmod(s[-1],d)
    while cx*bi<bx*ci:
      s.pop()
      s[-1]=(bx+cx)*d+bi+ci
      if len(s)==1:
        break
      bx,bi=divmod(s[-2],d)
      cx,ci=divmod(s[-1],d)
  ans=[]
  for ii in range(len(s)):
    sx,si=divmod(s[ii],d)
    ans+=[str(sx/si)]*si
  print(" ".join(ans))
if __name__ == "__main__":
  main()