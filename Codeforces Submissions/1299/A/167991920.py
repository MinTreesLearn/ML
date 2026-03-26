import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
li = list(map(int, input().split()))

total_cts = [0] * 31
cts = [[0] * 31 for _ in range(n)]
for i in range(n):
    v = li[i]
    bv = bin(v)
    
    cur = 0
    for j in range(len(bv) - 1, 1, -1):
        if bv[j] == '1':
            cts[i][cur] = 1
            total_cts[cur] += 1
        cur += 1
        
to_save = -1
for i in range(30, -1, -1):
    if total_cts[i] == 1:
        to_save = i
        break
        
if to_save == -1:
    print(*li)
else:
    target_i = -1
    for i in range(n):
        if cts[i][to_save] == 1:
            target_i = i
            break
            
    result = [li[target_i]]
    for i in range(n):
        if i != target_i:
            result.append(li[i])
            
    print(*result)