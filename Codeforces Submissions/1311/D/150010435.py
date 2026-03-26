import sys
for _ in range(int(sys.stdin.readline())):
    a,b,c=map(int,sys.stdin.readline().split())
    a1,b1,c1=a,b,c
    count=10**9+7
    for i in range(1,a*2+1):
        for j in range(i,2*b+1,i):
            for x in range(j,2*c+1,j):
                y=abs(a-i)+abs(b-j)+abs(c-x)
                if y<count:
                    a1=i
                    b1=j
                    c1=x
                    count=y
    print(count)
    print(a1,b1,c1)
