import math
# def sieve(n):
#     arr = [True]*(n+1)
#     arr[0] = False
#     arr[1] = False
#     for p in range(2,math.ceil(pow(n,0.5))):
#         if arr[p] == False:
#             continue
#         for j in range(p*p,n+1,p):
#             arr[j] = False
#     res = []
#     for p in range(2,n+1):
#         if arr[p]:
#             res.append(p)
#     return res


def prime_factors(n):
    arr = []
    # make it odd
    s = bin(n)[2:][::-1]
    zero = 0
    for e in s:
        if e == '0':
            zero += 1
        else:
            break
    n = n >> zero
    if zero >= 1:
        arr.append(2)

    for e in range(3,math.ceil(pow(n,0.5)) + 1,2):
        if n%e == 0:
            arr.append(e)
        while n % e == 0:
            n = n//e
    if n > 1: arr.append(n)
    return arr

# print(prime_factors(2*3*107*31*27*193))

def find(arr,e):
    res = 0
    for x in arr:
        if x < e:
            res += e - x    
            # print(e-x%e)
        else:
            res += min(x%e,e - x%e)
            # print(min(x%e,e - x%e))
    return res

import random

n = int(input())
arr  = [int(x) for x in input().split()]
limit = min(8, n)
iterations = [x for x in range(n)]
random.shuffle(iterations)
iterations = iterations[:limit]
prime_list = set()
for i in iterations:
    x = arr[i]
    for d in [x-1,x,x+1]:
        prime_list = prime_list.union(set(prime_factors(d)))

res = n
for prime in prime_list:
    res = min(res,find(arr,prime))

print(res)
