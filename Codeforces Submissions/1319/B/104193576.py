from collections import defaultdict


def read_ints():
    return map(int, input().split())


n, = read_ints()
b_seq = tuple(read_ints())
results = defaultdict(int)

for i, b in enumerate(b_seq):
    results[i - b] += b

result = max(results.values())
print(result)
