i=lambda:input().split()
i();a,b=i(),i();c=d=0
for i,x in enumerate(a):c+=x>b[i];d+=b[i]>x
print([[1--(d+1-c)//max(1,c),1][c>d],-1][c<1])