import math

n,m=([int(x) for x in input().split()])
if n==m:
    print(0)
else:
    if (m/n)%2!=0 and (m/n)%3!=0:
        print(-1)
    else:
        a=0
        b=m/n
        while b%2==0:
            b=b//2
            a=a+1
        c = 0
        d = m /n
        while d % 3 == 0:
            d = d // 3
            c = c + 1
        if math.gcd(int(b),int(d))==1:
            print(a+c)
        else:
            print(-1)