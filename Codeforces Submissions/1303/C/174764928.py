a = ord('a')

for _ in range(int(input())):
    s = input()
    t = [s[0]]
    i = 0
    for l in s[1:]:
        if i > 0 and l == t[i-1]:
            i -= 1
        elif i < len(t) - 1 and l == t[i+1]:
            i += 1
        elif l in t:
            print('NO')
            break
        elif i == len(t) - 1:
            t.append(l)
            i += 1
        elif i == 0:
            t.insert(0, l)
            i = 0
        else:
            print('NO')
            break
    else:
        print('YES')
        for l in range(26):
            l = chr(l + a)
            if l not in t:
                t.append(l)
        print(''.join(t))
