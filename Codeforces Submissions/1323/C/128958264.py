n=int(input())
s=input()
c=0
q=0
for i in range ( len(s)):
    if s[i]=="(":
        c+=1
    else:
        c+=-1
        if c<0:
            q=q+2
if c!=0:
    print(-1)
else:
    print(q)