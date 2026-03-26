def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if a.count(-1) == n: return print(0, 0)

    store = []
    for i in range(n):
        if a[i] == -1: continue
        neighbours = []
        if i > 0: neighbours.append(a[i-1])
        if i < n-1: neighbours.append(a[i+1])

        if -1 in neighbours: store.append(a[i])
    
    up = max(store)
    down = min(store)
    mid = (up + down) // 2
    for i in range(n):
        if a[i] == -1: a[i] = mid
    

    # print('a:', store)
    print(max([abs(a[i+1]-a[i]) for i in range(n-1)]), mid)
        
    

    
for case in range(int(input())):
    solve()