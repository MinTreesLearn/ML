import random
prime = [1] * (10**6 + 100)
div = 2
while div < 1002:
	i = 2
	while div * i <= 10**6+99:
		prime[div*i] = 0
		i += 1
	div += 1
	while prime[div] == 0 and div < 1002:
		div += 1
prim = []
for i in range(2,10**6+100):
	if prime[i] == 1:
		prim.append(i)
def primes(a):
	odp = set()
	aa = a
	i = 0
	while prim[i]**2 <= a and aa > 1:
		if aa%prim[i] == 0:
			aa//=prim[i]
			odp.add(prim[i])
		else:
			i += 1
	if aa > 1:
		odp.add(aa)
	return odp
n = int(input())
l = list(map(int,input().split()))
kandydatski = set([2])
for i in range(6):
	elt = l[random.randint(0,n-1)]
	for j in range(3):
		kandydatski = kandydatski.union(primes(elt-1+j))
def tru_odl(a,p):
	if a < p:
		return p - a
	else:
		return min(a%p, p-(a%p))
wyn = 347239578249758934
for k in kandydatski:
	temp = 0
	for i in range(n):
		temp += tru_odl(l[i],k)
	wyn = min(wyn, temp)
print(wyn)