n = int(input())
a = [0]*int(1e6)
x = list(map(int, input().split()))
ans = 0
for i in range(n):
    a[x[i]-i]+=x[i] 
    ans = max(a[x[i]-i],ans)
print(ans)