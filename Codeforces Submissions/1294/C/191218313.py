# output = "YES" and `a,b,c` or no
# 2 <= a,b,c
# a.b.c = n

# input: t
# n => 2<= n <= 10^9
import math
t = int(input())
for _ in range(t):
    n = int(input())
    ans = []
    N = math.floor(n ** 0.5)
    for i in range(2,N):
        if n % i == 0:
            n = n // i
            ans.append(i)
        if len(ans) == 2:
            ans.append(n)
            break
    if len(ans) < 3:
        print('NO')
    elif ans[-1] == ans[1] or ans[-1] == ans[0]:
        print('NO')
    else:
        print('YES')
        print(*ans)
            
            
            
    
    
            