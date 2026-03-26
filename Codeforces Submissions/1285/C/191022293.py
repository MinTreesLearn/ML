from collections import Counter
import math

n = int(input())

num = Counter()
ans = 0

for i in range(1, int(n ** 0.5) + 1):
    if n % i == 0:
        num[i] = n // i

re = num.most_common()
re.reverse()

for i in re:
    if math.gcd(i[0], i[1]) == 1:
        print(*i)
        break
