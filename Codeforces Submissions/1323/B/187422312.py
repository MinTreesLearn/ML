[a,a,area]=list(map(int,input().split(" ")))
a=[len(i)for i in input().replace(' ','').split('0')if len(i)>0]
b=[len(i)for i in input().replace(' ','').split('0')if len(i)>0]
ans=0

fac=[]
k=1
while(k*k<=area):
  if area%k==0:
    fac.append((k,area//k))
  k+=1
fac+=[(j,i)for i,j in fac if i!=j]
for x,y in fac:
  ans+=sum(i-x+1 for i in a if x<=i)*sum(j-y+1 for j in b if y<=j)
print(ans)