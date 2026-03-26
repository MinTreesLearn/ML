from sys import stdin
input=lambda :stdin.readline()[:-1]

n=int(input())
s=[ord(i)-97 for i in input()]
c=[-1]*27
ans=[]
for i in s:
  mx=max(c[i+1:])
  c[i]=mx+1
  ans.append(mx+2)
print(max(ans))
print(*ans)