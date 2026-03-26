import string
def solve():
	G=int(input())
	for H in range(G):
		E=input().strip();A=[];A.append(E[0]);C=0;D=set(A);F=False
		for B in E[1:]:
			if C>0 and B==A[C-1]:C-=1
			elif C<len(A)-1 and B==A[C+1]:C+=1
			elif C==len(A)-1 and B not in D:A.append(B);D.add(B);C+=1
			elif C==0 and B not in D:A=[B]+A;D.add(B)
			else:F=True
		if F:print('NO')
		else:
			print('YES')
			for B in string.ascii_lowercase:
				if B not in D:A.append(B)
			print(''.join(A))
if __name__=='__main__':solve()