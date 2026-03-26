n = int(input())
li = list(map(int, input().split()))

n_loc = -1
cumul = 0
for i in range(n - 1):
    cumul += li[i]
    if cumul == n - 1:
        n_loc = i + 1
        break
        
    if cumul < 0:
        cumul = 0
        
if n_loc == -1:
    cumul = 0
    for i in range(n - 2, -1, -1):
        cumul += li[i]
        if cumul == -(n - 1):
            n_loc = i
            break
        if cumul > 0:
            cumul = 0
            
if n_loc == -1:
    print(-1)
else:
    result = [0] * n
    result[n_loc] = n
    for i in range(n_loc - 1, -1, -1):
        result[i] = result[i + 1] - li[i]
        
    for i in range(n_loc + 1, n):
        result[i] = result[i - 1] + li[i - 1]
        
    if sorted(result) != list(range(1, n + 1)):
        print(-1)
    else:
        print(*result)