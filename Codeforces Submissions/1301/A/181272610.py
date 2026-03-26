result=""
for i in range(0,int(input())):
	a=input()
	b=input()
	c=input()
	flag=True
	n=0
	for k in range(0,len(a)):
		if (a[k]==c[k]) or (b[k]==c[k]):
			n+=1
		elif  (a[k]==b[k]):
			n+=2
		else:
			flag=False
			break
	if flag and n<=len(a):
		result+="YES\n"
	else:
		result+="NO\n"
print(result.rstrip("\n"))