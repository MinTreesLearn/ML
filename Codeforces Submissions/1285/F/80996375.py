#AUTHOR-Jonte_98
import sys
from math import gcd
input = sys.stdin.readline
 
n = int(input())
A = [int(i) for i in input().split()]
divisors = [[] for _ in range(10**5+2)]
mobius = [1 for _ in range(10**5+2)]
#get all the divisors for every number from 1 to 10**5
for i in range(1,10**5+1):
    for j in range(i,10**5+1,i):
        divisors[j].append(i)

#mobius magic,have got no clue how this is obtained, and what it tells
for i in range(1,10**5+1):
    for d in divisors[int(i)]:
        if d == 1:
            continue
        if i % (d**2) == 0 or mobius[int(i)] == 0:
            mobius[int(i)] = 0
        elif len(divisors[int(i)]) == 2:
            mobius[int(i)] = -1
        else:
            mobius[int(i)] = mobius[int(d)] * mobius[int(i / d)]
 
#get all the divisors of all the numbers in a set
numbers = set(A)
for i in A:
    for d in divisors[i]:
        numbers.add(d)
#reverse all the numbers and get a frequency list to store the count of
#numbers in the 'number' set a divisor divides perfectly
numbers = sorted(list(numbers), reverse=True)
stack = []
cnt = [0] * (10**5+2)
for i in numbers:
    stack.append(i)
    for d in divisors[i]:
        cnt[d] += 1
ans = 0
#keep on popping the stack till all the coprime numbers for a particular
#number is found (refer to editorial if
#any doubt regarding this operation)
#and their products calculated, store it in 'ans'
#if current product greater than 'ans'
for x in numbers:
    num_co_prime = sum(cnt[d] * mobius[d] for d in divisors[x])
    while num_co_prime > 0:
        a = stack.pop()
        for d in divisors[a]:
            cnt[d] -= 1
        if gcd(a,x) > 1:
            continue
        ans = max(a*x,ans)
        num_co_prime-=1
 
print(ans)
