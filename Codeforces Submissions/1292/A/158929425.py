def solve():
    n,q = (int(i) for i in input().split(" "))
    
    arr = [[0,0] for i in range(n)]
    count = 1
    
    for t in range(q):
        a,b = (int(i)-1 for i in input().split(" "))
        d = 1 if arr[b][a]==1 else -1
        arr[b][a] = 1 - arr[b][a]
        
        for dy in range(-1, 2):
            if b+dy>=0 and b+dy<n:
                if arr[b+dy][1-a]==1:
                    count+=d
        
        if count==1:
            print("YES")
        else:
            print("NO")
        
t = 1#int(input())

for _ in range(t):
    solve()