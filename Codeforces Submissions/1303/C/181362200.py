def solve():
    s = input()
    a = ['']*60
    i = 30
    vis = set()
    for j in range(len(s)):
        if j == 0:
            a[i] = s[j]
            vis.add(s[j])
        elif a[i-1] == s[j]: i -= 1
        elif a[i+1] == s[j]: i += 1
        elif a[i-1] == '':
            if s[j] in vis:
                print('NO')
                return
            vis.add(s[j])
            i -= 1
            a[i] = s[j]
        elif a[i+1] == '':
            if s[j] in vis:
                print('NO')
                return
            vis.add(s[j])
            i += 1
            a[i] = s[j]
        else:
            print('NO')
            return
    print('YES')
    vis = set()
    for i in range(len(a)):
        if a[i] != '':
            print(a[i], end='')
            vis.add(a[i])
    for i in range(26):
        c = chr(i+97)
        if c not in vis: print(c, end='')
    print()


for _ in range(int(input())):
    solve()
