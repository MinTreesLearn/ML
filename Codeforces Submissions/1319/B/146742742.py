n = int(input())
progressions = {}
b = list(map(int,input().split()))
for i in range(n):
    progressions[b[i] - i] = 0
for i in range(n):
    progressions[b[i] - i] += b[i]

a = []
for i in progressions.items():
    a.append(i[1])
print(max(a))
