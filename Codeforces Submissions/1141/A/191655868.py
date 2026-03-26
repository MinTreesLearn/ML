n , m = list(map(int ,input().split()))
count = 0
while m > n : 
    if(m % (n*2) == 0):
        n *= 2
        count += 1 
    else:
        n *= 3 
        count += 1 
if(n == m):
    print(count)
else:
    print(-1)