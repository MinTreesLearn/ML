n = int(input())
s = input()
ans = "YES"
mx = 'a'
p = ''
lst = 'a'
for i in range(n):
    if s[i] >= mx:
        mx = s[i]
        p += '0'
    elif s[i] == mx and i > 0 and s[i - 1] == mx:
        p += '0'
    elif s[i] == mx or s[i] < mx:
        p += '1'
        if lst > s[i]:
            ans = "NO"
        else:
            lst = s[i]
if ans == "NO":
    print(ans)
else:
    print(ans)
    print(p)
