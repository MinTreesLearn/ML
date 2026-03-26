t=int(input())
for i in range(t):
    a,b,x,y=[int(j) for j in input().split()]
    z1=(a-1-x)*b
    z2=x*b
    z3=a*(b-1-y)
    z4=a*y
    print(max(z1,z2,z3,z4))