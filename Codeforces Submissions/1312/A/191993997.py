t=int(input())
op=[]
for i in range(t):
    m,n=map(int,input().split(' '))
    if m%n==0:
        op.append('YES')
    else:
        op.append('NO')
for i in op:
    print(i)