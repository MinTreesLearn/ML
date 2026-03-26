def lex(s,k):
	if (len(s)-k)%2==1:
		t = s[k-1:] + s[0:k-1]
	else:
		t = s[k-1:] + s[0:k-1][::-1]
	return t

for times in range(int(input())):
	n = int(input())
	s = input()
	st = lex(s,1)
	ansk = 1
	for k in range(2,n+1):
		if lex(s,k)<st:
			st = lex(s,k)
			ansk = k
	print(st)
	print(ansk)