def Q(W):
    for j in W:
        if R[j] and s[j]!=s[i]:
            return ord(s[j])==ord(s[i])-1
    return 0
E=0
n=int(input())
s=input()
R=[1]*n
for i in sorted(range(n),key=s.__getitem__)[::-1]:
    if Q(range(i-1,-1,-1)) or Q(range(i+1,n)):
        E+=1
        R[i]=0
print(E)