import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int,minp().split())

def sub(s1,s2):
	d = dict()
	for i in s1:
		d[i] = d.get(i,0)+1
	for i in s2:
		d[i] = d.get(i,0)-1
	for j in d:
		if d[j] > 0:
			return j
	return 'a'

ans = ''

def emit(l,r):
	a = []
	print('?', l, r)
	sys.stdout.flush()
	z = (r-l+1)*(r-l+2)//2
	while len(a) < z:
		q = minp()
		if q == '-':
			exit(0)
		if len(q) != 0:
			a.append(q)
	return a
	a = hm(ans[l-1:r])
	if len(a) != z:
		raise Exception("wrong %d %d"%(len(a),z))
	return a

def solve():
	#global ans
	#ans = minp()
	#n = len(ans)
	n = mint()
	a = emit(1,n)
	if n == 1:
		print('!',a[0])
		return
	b = emit(1,n-1)
	d = dict()
	for i in a:
		z = ''.join(sorted(i))
		d[z] = d.get(z,0)+1
	for i in b:
		z = ''.join(sorted(i))
		d[z] = d.get(z,0)-1
	z = []
	for j in d:
		if d[j] > 0:
			z.append(j)
	z.sort(key=lambda a: len(a))
	#print(z)
	s = ''
	for i in z:
		#print(i,s)
		s = sub(i,s) + s
	print("!", s)
	sys.stdout.flush()

from random import randint

def shufled(s):
	s = list(s)
	r = ''
	for i in range(len(s)):
		r += s.pop(randint(0,len(s)-1))
	return r

def hm(s):
	a = []
	n = len(s)
	for i in range(0,n):
		for j in range(i+1,n+1):
			a.append((j-i,''.join(shufled(s[i:j]))))
	a.sort()
	print(*a,sep='\n')
	return [i[1] for i in a]#

solve()
