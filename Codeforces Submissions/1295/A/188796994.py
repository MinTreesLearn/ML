t = int(input())
for i in range(t):
    n = int(input())
    
    k = n // 2
    m = n % 2
    ans = ""
    if m == 0:
        ans += "1" * k
    else:
        ans += "7"
        ans += "1" * (k - 1)     
        
        
    print(ans)
    
    
    