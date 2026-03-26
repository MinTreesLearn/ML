n,m=map(int,input().split())
ans=[1]
if n==1 and m==0:
    print(*ans)
    exit()
elif n==2 and m==0:
    ans.append(2)
    print(*ans)
    exit()
suma=0
ans=[1,2]
for i in range(3,n+1):
    if suma+(i-1)//2<m:
        ans.append(i)
        suma+=(i-1)//2
    else:
        ans.append(i-1+(i-2*(m-suma)))
        suma=m
        break
if suma<m:
    print(-1)
    exit()
ceil=10**9
maxa=max(ans)
while len(ans)<n:
    ans.append(ceil)
    ceil-=maxa+1
ans=sorted(ans)
print(*ans)