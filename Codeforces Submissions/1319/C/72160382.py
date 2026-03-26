n = int(input())
s = list(input())
ans = 0
alphabet = list('abcdefghijklmnopqrstuvwxyz')
s_by_alph = {}
for letter in alphabet:
    s_by_alph[letter] = []
for i in range(n):
    s_by_alph[s[i]].append(i)
removed = set()
for i in range(-1, -26, -1):
    for k in s_by_alph[alphabet[i]]:
        if k != 0:
            k1 = k - 1
            while k1 >= 0 and (k1 in removed or s[k1] == s[k]):
                k1 -= 1
        else:
            k1 = k
        if k != n - 1:    
            k2 = k + 1
            while k2 < n and (k2 in removed or s[k2] == s[k]):
                k2 += 1
        else:
            k2 = n - 1
        if k1 > -1 and s[k1] == alphabet[i - 1] or k2 < n and s[k2] == alphabet[i - 1]:
            ans += 1
            removed.add(k)
print(ans)