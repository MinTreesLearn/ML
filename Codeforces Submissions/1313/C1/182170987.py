from typing import List, Tuple

def return_max(a: List[int]) -> Tuple[List[int], int]:
    ans = []; prev_min = float('inf')
    s = 0
    for e in a:
        if e < prev_min:
            ans.append(e)
            prev_min = e
            s += e
        else:
            ans.append(prev_min)
            s += prev_min

    return ans, s

n = int(input())
m = [int(x) for x in input().split()]


maxim = float('-inf')
ans = None
for peak_ind in range(n):
    first_half, first_sum = return_max(m[:peak_ind + 1][::-1])
    first_half = first_half[::-1]
    second_half, second_sum = return_max(m[peak_ind:])
    curr_sum = first_sum + second_sum - m[peak_ind]
    if curr_sum > maxim:
        maxim = curr_sum
        ans = first_half[:-1] + second_half
    

print(' '.join([str(e) for e in ans]))
    
    
