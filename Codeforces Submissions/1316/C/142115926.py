R = lambda: list(map(int,input().split()));n,m,p=R();a,b=R(),R();i=0;j=0
while a[i]%p==0:i+=1
while b[j]%p==0:j+=1
print(i+j)