from random import *

def ff(s):
	maxans=0
	for ind,i in enumerate(s):
		if((ind+1 < len(s) and s[ind+1]+1==i) or (ind-1 > -1 and s[ind-1]+1==i)):
			s1=s[0:ind]+s[ind+1:len(s)]
			maxans=max(maxans, 1+f(s1))
	return maxans;
'''	
s=[i%26+1 for i in range(1,10)]
print(f(s))
'''
alp='abcdefghijklmnopqrstuvwxyz'
'''
def f(s, ops=0, total=0):
	opps=0
	mx=max(s)
	for ch in range(mx,-1,-1):
		for ind, i in enumerate(s[::-1]):
			ind=len(s)-ind-1;
			#print(ch)
			if((ind+1 < len(s) and s[ind+1]+1==i) or (ind-1 > -1 and s[ind-1]+1==i)) and ch==i:
				s=s[0:ind]+s[ind+1:len(s)]
				print(i, ch)
				opps+=1
				print(s)
	if(opps==ops and ops==0):
		return (total, s);
	else:
		return f(s, opps, total+opps);
'''		
def f(s):
	gc=0
	change=-1
	while(change!=0):
		change=0;
		for ch in range(max(s), min(s)-1, -1):
			slen=len(s)
			lchange=-1
			while(lchange!=0):
				lchange=0
				for i in range(slen-1,-1,-1):
					if( (i+1<slen and s[i+1]+1==s[i]) or (i-1>=0 and s[i-1]+1==s[i])) and (ch==s[i]):
						s=s[0:i]+s[i+1:slen]
						slen-=1
						#print(s)
						change+=1
						gc+=1
						lchange+=1
	return gc

_=input()

'''
for i in range(1000):
	s=[randint(0,10000)%2 for i in range(10)]
	print(s,ff(s),f(s))
	if(ff(s)!=f(s)):
		break
'''
s=[ord(i) for i in input()]
#print(s)
print(f(s))

