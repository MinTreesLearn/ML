# import sys,os,io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007
# MOD = 998244353


def bin32(num):
    return '{0:032b}'.format(num)

def add(x,y):
    return (x+y)%MOD

def sub(x,y):
    return (x-y+MOD)%MOD

def mul(x,y):
    return (x*y)%MOD

def gcd(x,y):
    if y == 0:
        return x
    return gcd(y,x%y)

def lcm(x,y):
    return (x*y)//gcd(x,y)

def power(x,y):
    res = 1
    x%=MOD
    while y!=0:
        if y&1 :
            res = mul(res,x)
        y>>=1
        x = mul(x,x)
        
    return res
        
def mod_inv(n):
    return power(n,MOD-2)

def prob(p,q):
    return mul(p,power(q,MOD-2))    
  
def ii():
    return int(input())

def li():
    return [int(i) for i in input().split()]

def ls():
    return [i for i in input().split()]

s = input()
n = len(s)

f = []

tmp = [0 for i in range(26)]

tmp[ord(s[0]) - 97] +=1
f.append(tmp)

for i in range(1 , n):
    tmp = f[-1][:]
    tmp[ord(s[i]) - 97] +=1
    f.append(tmp)

q = ii()
for  _ in range(q):
    l,r = li()
    l-=1
    r-=1
    if r == l:
        print("Yes")
        continue
    if s[l]!= s[r]:
        print("Yes")
        continue
    cnt  = 0
    for i in range(26):
        if l!= 0:
            x = f[r][i] - f[l-1][i]
            if x > 0:
                cnt+=1
        else:
            x = f[r][i]
            if x > 0:
                cnt+=1
    if cnt > 2:
        print("Yes")
        continue
    print("No")
