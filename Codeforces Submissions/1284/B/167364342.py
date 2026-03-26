from bisect import bisect_left
import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
li = []
for _ in range(n):
    _, *temp = map(int, input().split())
    li.append(temp)

asc_c = 0
no_asc_c = 0

no_asc_maxes = []
no_asc_mins = []
for temp in li:
    cur_min = temp[0]
    min_v = temp[0]
    max_v = temp[0]
    is_asc = False
    for i in range(1, len(temp)):
        min_v = min(min_v, temp[i])
        max_v = max(max_v, temp[i])
        if cur_min < temp[i]:
            is_asc = True
            break
        cur_min = min(cur_min, temp[i])
    
    if is_asc:
        asc_c += 1
    else:
        no_asc_c += 1
        no_asc_maxes.append(max_v)
        no_asc_mins.append(min_v)
        
total = n * asc_c + asc_c * no_asc_c
        
no_asc_maxes_len = len(no_asc_maxes)
no_asc_maxes.sort()
for min_v in no_asc_mins:
    total += no_asc_maxes_len - bisect_left(no_asc_maxes, min_v + 0.1)
    
print(total)