x=int(input())
ans=[1,x]
from math import lcm
for i in range(1,int(x**0.5)+1):
	if x%i==0:
		if lcm(i,x//i)==x:
			if max(ans)>max(i,x//i):
				ans=[i,x//i]
			
print(*ans)