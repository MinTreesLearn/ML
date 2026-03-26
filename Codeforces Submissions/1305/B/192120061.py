s = list(input())
ans = []
while True:
    temp = []
    l = 0
    r = len(s) - 1
    while l < r:
        while l < r and s[l] != "(":
            l += 1
        while l < r and s[r] != ")":
            r -= 1
        if l < r and s[l] == "(" and s[r] == ")":
            s[l] = "0"
            s[r] = "0"
            l += 1
            r -= 1
            temp.extend([l, r+2])
    if not temp:
        break
    ans.append(sorted(temp))
    new_s = []
    for ch in s:
        if ch != "0":
            new_s.append(ch)
    s = new_s
print(len(ans))
for a in ans:
    print(len(a))
    print(*a)