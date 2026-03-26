import math
n = int(input())
for i in range(1,int(n**0.5)+1):
    if n%i==0:
        if math.gcd(n//i,i) == 1:
            res = i
print(res,n//res)