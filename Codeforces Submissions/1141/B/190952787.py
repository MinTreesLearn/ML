n = int(input())
a = list(map(int, input().split()))
groups = [a[0]]
counts = [1]
for i in range(1, len(a)):
    ai = a[i]
    if groups[-1] == ai:
        counts[-1] += 1
    else:
        groups.append(ai)
        counts.append(1)

best_count = 0
if groups[-1] == 1 and groups[0] == 1:
    best_count = counts[-1] + counts[0]
for i in range(len(counts)):
    if groups[i] == 1:
        best_count = max(best_count, counts[i])
print(best_count)