n=int(input())
a=list(map(int,input().split()))
e=n//2
o=(n-e)
ptf=[[[0,0] for i in range(e+2)] for j in range(o+2)]
dt={}
for i in range(n):
    if(a[i]!=0):
        dt[i+1]=a[i]
for i in range(o+1):
    for j in range(e+1):
        if(i==0):
            ptf[i][j][0]=99999
        if(j==0):
            ptf[i][j][1]=99999
        if i+j in dt:
            if(dt[i+j]%2==1):
                ptf[i][j][1]=99999
            else:
                ptf[i][j][0]=99999
ptf[0][0][0]=0
ptf[0][0][1]=0
for i in range(o+1):
    for j in range(e+1):
        if(ptf[i][j+1][1]<9999):
            ptf[i][j+1][1]=min(ptf[i][j][1],ptf[i][j][0]+1)
        if(ptf[i+1][j][0]<9999):
            ptf[i+1][j][0]=min(ptf[i][j][0],ptf[i][j][1]+1)
print(min(ptf[i][j][0],ptf[i][j][1]))