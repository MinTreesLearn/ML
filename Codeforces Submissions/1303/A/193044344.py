# LUOGU_RID: 101845216
for _ in range(int(input())):
    s = input()
    l = 0
    while l < len(s) and s[l] == '0':
        l += 1
    r = len(s)
    while r > l and s[r - 1] == '0':
        r -= 1
    print(r - l - s.count('1'))