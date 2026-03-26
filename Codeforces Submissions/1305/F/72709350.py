import random

# Sieve
sieve_primes = []
PRIME_LIMIT = int(1e6)
sieve = [False for i in range(0,PRIME_LIMIT)]
for i in range(2,PRIME_LIMIT):
    if not sieve[i]:
        sieve_primes.append(i)
        for j in range(i*i, PRIME_LIMIT, i):
            sieve[j]=True

# Input
n = int(input())
arr=list(map(int, input().split()))

# Construct search space Primes 
primes = set()
def addPrime(num):
    for sieve_prime in sieve_primes:
        if num%sieve_prime == 0:
            primes.add(sieve_prime)
            while num%sieve_prime == 0:
                num//=sieve_prime
    if num>1:
        primes.add(num)

# (Could use probability calculations here to reduce search space)
random.shuffle(arr)
arr_set=list(set(arr))
for num in arr_set[:20]:
    if num > 1:
        addPrime(num)
    addPrime(num+1)
    if num > 2:
        addPrime(num-1)

# Find answer
ans = n

# Function to find answer based on input prime
def findAns(prime):
    global ans
    curr_ans = 0
    for num in arr:
        if num<prime:
            curr_ans += prime-num
        else:
            curr_ans += min(num%prime, prime - num%prime)
        if curr_ans >= ans:
            return
    ans = min(curr_ans, ans)

for prime in primes:
    findAns(prime)
    if ans == 0: break

print(ans)