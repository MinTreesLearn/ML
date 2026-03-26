
import math

def u(x,a):
    for m in divisors[x]:
        sum[m]+=a
def coprime(x):
	count = 0
	for i in divisors[x]:
	   count+=sum[i]*mobius[i]
	return count

n = int(input())

a = input().split(" ")

maxlcm = 0
b = [False]*100010

for x in range(n):
    a[x] = int(a[x])
    maxlcm = max(a[x],maxlcm)
    b[a[x]] = True

a.sort(reverse=True)
m = 100005
sum = [0]*(m+5)
mobius = [0]*(m+5)
divisors = {}
for i in range(1,m):
    for j in range(i,m,i):
        try:
            divisors[j].append(i)
        except:
            divisors[j] = [1]
    if(i==1):
        mobius[i] = 1
    elif ((i/divisors[i][1]%divisors[i][1])==0):
        mobius[i]=0
    else:
        mobius[i] = -mobius[int(i/divisors[i][1])]
for g in range(1,m):
    s = []
    for x in range(int(m/g)):
        x = int(m/g)-x

        if(not b[x*g]):
            continue

        c = coprime(x)
        while c:

            if(math.gcd(x,s[-1])==1):
                maxlcm = max(maxlcm,x*g*s[-1])
                c-=1
            u(s[-1],-1)
            s.pop(-1)
        u(x,1)
        s.append(x)
    while(len(s)!=0):
        u(s[-1],-1)
        s.pop(-1)
print(maxlcm)
