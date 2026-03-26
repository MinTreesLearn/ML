from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))


mod = 998244353
def add(a , b):return ((a%mod) + (b%mod))%mod
def sub(a , b):return (a - b + mod)%mod
def mul(a , b):return ((a%mod) * (b%mod))%mod
def ncr(n , r):return mul(fact[n] , mul(facti[n - r] , facti[r]))
def div(a , b):return mul(a , pow(b , mod - 2 , mod))


def answer():


    ans = 0
    for x in range(1 , n + 1):
        w = (n - x + 1) * (n - x + 1)
        ways = mul(fact[x] , fact[n - x])
        ways = mul(ways , w)
        ans = add(ans , ways)


    return ans

    

for T in range(1):

    n , mod = inp()

    fact , facti = [1] , [1]
    size = 3 * (10**5) + 1
    for i in range(1 , size):
        fact.append(mul(fact[-1] , i))
        facti.append(pow(fact[-1] , mod - 2 , mod))

    print(answer())
