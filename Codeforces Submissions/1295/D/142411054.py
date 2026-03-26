from sys import stdin
input = stdin.readline

def phi(n):

    num , i , x = n , 2 , n
    while(i * i <= x):

        if(n % i == 0):

            while(n % i == 0):
                n //= i

            num = (num // i) * (i - 1)

        i += 1

    if(n > 1):
        num = (num // n) * (n - 1)

    return num

def gcd(a , b):

    if(b == 0):return a
    return gcd(b , a%b)

def answer():

    g = gcd(a , m)
    
    return phi(m//g)

   
for T in range(int(input())):

    a , m = map(int,input().split())

    print(answer())
