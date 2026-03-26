from collections import defaultdict
n = int(input())

left = input()
right = input()

left_inds = defaultdict(list)
right_inds = defaultdict(list)

for idx, char in enumerate(left):
    left_inds[char].append(idx+1)
for idx, char in enumerate(right):
    right_inds[char].append(idx+1)

# print(right_inds)
# print(left_inds)

ans = []
if "?" in left_inds:
    for char in right_inds:
        if char == "?": continue
        while len(right_inds[char]) > len(left_inds[char]) and left_inds["?"]:
            idx1 = left_inds["?"].pop()
            idx2 = right_inds[char].pop()
            ans.append((idx1, idx2))

if "?" in right_inds:
    for char in left_inds:
        while len(left_inds[char]) > len(right_inds[char]) and right_inds["?"]:
            idx1 = right_inds["?"].pop()
            idx2 = left_inds[char].pop()
            ans.append((idx2, idx1))

for char in right_inds:
    res = min(len(right_inds[char]), len(left_inds[char]))
    for _ in range(res):
        idx1 = left_inds[char].pop()
        idx2 = right_inds[char].pop()

        ans.append((idx1, idx2))

print(len(ans))
for a, b in ans:
    print(a, b)



