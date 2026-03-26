t = int(input())

#prime sieve
MAX = 32000 #sqrt(10**9)
primeSieve = [True]*MAX
primes = []
primeSieve[0] = primeSieve[1] = False
for i in range(2,MAX):
    if primeSieve[i] == True:
        primes.append(i)
        for j in range(i*i, MAX, i):
            primeSieve[j] = False

for _ in range(t):
    n = int(input())
    nums = []

    i = 0
    while i<len(primes) and n > 1:
        if n%primes[i] == 0:
            nums.append(primes[i])
            n //= primes[i]

            if len(nums) == 2:
                break

            if n%(primes[i]**2) == 0:
                nums.append(primes[i]**2)
                n //= primes[i]**2
                break
        i += 1
        
    if len(nums) >=2 and n not in nums+[1]:
        print("YES")
        print(*nums,n)
    else:
        print("NO")
