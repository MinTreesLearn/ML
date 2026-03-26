n = int(input())
b = list(map(int, input().split()))
smth = dict()
for i in range(n):
    if not (b[i] - i) in smth:
        smth[b[i] - i] = 0
    smth[b[i] - i] += b[i]
ans = 0
for el in smth:
    ans = max(ans, smth[el])
print(ans)