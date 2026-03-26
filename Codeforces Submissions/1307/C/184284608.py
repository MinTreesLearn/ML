from sys import stdin
from collections import defaultdict
import bisect
input = stdin.readline 

s = input(); set_s = set()
inds_by_letter = defaultdict(list)

for ind, elem in enumerate(s):
    inds_by_letter[elem].append(ind); set_s.add(elem)

ans = max(len(inds_by_letter[letter]) for letter in inds_by_letter)


for l1 in set_s:
    for l2 in set_s:
        res = 0
        for ind1 in inds_by_letter[l1]:
            pos = bisect.bisect_left(inds_by_letter[l2], ind1)
            res += pos

        ans = max(ans, res)

print(ans)



        



        