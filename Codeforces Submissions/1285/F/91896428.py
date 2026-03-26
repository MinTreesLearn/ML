
import math

def update(x,a):
    for m in div[x]:
        cnt[m]+=a
def coprime(x):
	count = 0
	for i in div[x]:
	   count+=cnt[i]*u[i]
	return count





n = int(input())


a = input().split(" ")

ans = 0
b = [False]*1000010

for x in range(n):
    a[x] = int(a[x])
    ans = max(a[x],ans)
    b[a[x]] = True

a.sort(reverse=True)
m = 100005
cnt = [0]*(m+5)
u = [0]*(m+5)
div= {}
for i in range(1,m):
    for j in range(i,m,i):
        try:
            div[j].append(i)
        except:
            div[j] = [1]
    if(i==1):
        u[i] = 1
    elif ((i/div[i][1]%div[i][1])==0):
        u[i]=0
    else:
        u[i] = -u[int(i/div[i][1])]
for g in range(1,m):
    s = []
    for x in range(int(m/g)):
        x = int(m/g)-x

        if(not b[x*g]):
            continue

        c = coprime(x)
        while c:

            if(math.gcd(x,s[-1])==1):
                ans = max(ans,x*g*s[-1])
                c-=1
            update(s[-1],-1)
            s.pop(-1)
        update(x,1)
        s.append(x)
    while(len(s)!=0):
        update(s[-1],-1)
        s.pop(-1)
print(ans)
