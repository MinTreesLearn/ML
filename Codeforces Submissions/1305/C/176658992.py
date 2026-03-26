n , m = map(int, input().split())
l = list(map(int, input().split()))
pr = 1
if n > m: exit(print(0))
for i in range(n):
    for j in range(i+1,n):
        pr=pr*abs(l[i]-l[j])
        pr = pr%m
print(pr)