n, a, b, kill = map(int, input().split())
l = []
p = 0
for h in map(int, input().split()):
	r = (h - a)%(a+b)	
	if r <= b:
		l.append(r//a + (r % a != 0))
	else:
		p += 1
l.sort()
s = 0
for i in l:
	s += i
	if s > kill:
		break
	p += 1 
print(p)

    		 		 			  	 			 	   		   	