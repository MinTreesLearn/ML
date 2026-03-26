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
    nCopy = n
    nums = [1]

    i = 0
    while i<len(primes) and n > 1 and len(nums) < 3:
        if n%primes[i] == 0:
            nums.append(primes[i])
            while n%primes[i] == 0:
                n //= primes[i]
        else:
            i += 1

    if len(nums) == 2:
        if nCopy%nums[1]**3 == 0 and nCopy//(nums[1]**3) > nums[1]**2:
            print("YES")
            print(nums[1], nums[1]**2, nCopy//(nums[1]**3))
        else:
            print("NO")
    elif len(nums) > 2:
        if nCopy//(nums[1]*nums[2]) in nums:
            print("NO")
        else:
            print("YES")
            print(nums[1], nums[2], nCopy//(nums[1]*nums[2]))
    else:
        print("NO")