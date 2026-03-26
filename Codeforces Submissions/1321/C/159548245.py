n = int(input())
s = input()
ans=0
for i in range(122,97,-1):
	if len(s)==1:
		break
	j = 0
	while j<len(s):
		if len(s)==1:
			break
		if ord(s[j])==i:
			if j==0 or j==len(s)-1:
				if j==0 and ord(s[j+1])==i-1:
					ans+=1
					s = s[1:]
				elif j==len(s)-1 and ord(s[j-1])==i-1:
					ans+=1
					s = s[:len(s)-1]
					j+=1
				else:
					j+=1
			elif j>0 and j<len(s)-1:	
				if ord(s[j-1])==i-1 or ord(s[j+1])==i-1:
					ans+=1
					s = s[:j] + s[j+1:]
					j-=1
				else:
					j+=1
			else:
				j+=1
		else:
			j+=1
print(ans)