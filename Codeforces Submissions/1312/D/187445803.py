M=998244353
n,m=map(int,input().split())
f=[]
f.append(1)
for i in range(1,m+1):
    f.append( (f[i-1]*i)%M )
print( ( (f[m]*pow(f[n-1]*f[m-n+1],M-2,M)) * (n-2) * pow(2,n-3,M) ) %M )