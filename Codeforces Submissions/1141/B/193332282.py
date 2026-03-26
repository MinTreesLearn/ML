n = int(input())
a = input().split()

l, r = 0, n-1

while l < r and a[l] == '1':
    l += 1 

while l < r and a[r] == '1':
    r -= 1

max_t = l + n - 1 - r

curr_t = 0

for i in range(l, r+1):
    if a[i] == '1':
        curr_t += 1
    else:
        max_t = max(max_t, curr_t)
        curr_t = 0

print(max_t)