n = int(input())
a = list(map(int, input().split()))
r = 0

for i in range(29, -1, -1):
    c = 0
    for j in a:
        if (j >> i) & 1:
            c += 1
            r = j
    if c == 1:
        break

a.remove(r)

print(r, ' '.join(map(str, a)))

num_inp=lambda: int(input())
arr_inp=lambda: list(map(int,input().split()))
sp_inp=lambda: map(int,input().split())
str_inp=lambda:input()
