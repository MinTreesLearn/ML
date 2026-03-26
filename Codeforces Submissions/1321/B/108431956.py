n = int(input())
b = list(map(int, input().split()))
a = b.copy()
for i in range(n):
    b[i] -= i
x = dict()
for i in range(n):
    if not x.get(b[i], False):
        x[b[i]] = 0
    x[b[i]] += a[i]
print(max(x.values()))
    
    
    
