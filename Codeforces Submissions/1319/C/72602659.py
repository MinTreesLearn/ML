n = int(input())
s = input()
alph = list(set(s))
alph.sort(reverse=True)
s = list(s)
for i in alph:
    if i == alph[-1]:
        continue
    prev = -1
    cur = len(s)
    while prev != cur:
        j = 0
        while j < len(s):
            if s[j] == i:
                if j == 0:
                    if s[j + 1] == chr(ord(i) - 1):
                        s.pop(j)
                elif j == len(s) - 1:
                    if s[j - 1] == chr(ord(i) - 1):
                        s.pop(j)
                elif cur >= 3 and (s[j - 1] == chr(ord(i) - 1) or s[j + 1] == chr(ord(i) - 1)):
                    s.pop(j)
                    j -= 1
            j += 1
        prev = cur
        cur = len(s)
print(n - len(s))
        