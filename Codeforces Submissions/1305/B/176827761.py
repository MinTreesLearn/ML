s = input()
r = set()
def foo():
    global s, r
    rem = []
    p1, p2 = 0, len(s)-1
    op = True
    while p1 <= p2:
        if op: 
            if s[p1] == '(' and p1 not in r:
                rem.append(p1)
                op = False
            p1 += 1
        else:
            if s[p2] == ')' and p2 not in r:
                rem.append(p2)
                op = True
            p2 -= 1
    if not op: rem.pop()
    n = len(rem)
    r.update(rem)
    rem = ' '.join(map(lambda x : str(x+1), sorted(rem)))
    return n, rem

res = []
while True:
    n, rem = foo()
    if not n: break
    res.append((n, rem))
print(len(res))
for n, rem in res:
    print(n)
    print(rem)
	  			     	 	 	 	  	  					