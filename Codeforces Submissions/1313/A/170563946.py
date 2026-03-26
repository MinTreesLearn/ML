from bisect import bisect
l = '001 011 022 122 223 333 444'.split()
for _ in range(int(input())): print(bisect(l, '{}{}{}'.format(*sorted(min(int(s), 4) for s in input().split()))))