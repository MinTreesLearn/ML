import sys
input = sys.stdin.readline
from collections import defaultdict

for _ in range(int(input())):
    d = defaultdict(set)
    s = input()[:-1]
    n = len(s)
    for i in range(n):
        if i > 0:
            d[s[i]].add(s[i-1])
        if i < n-1:
            d[s[i]].add(s[i+1])
    w = set()
    e = []
    ew = 0
    for i in d:
        if i not in w:
            q = [(i, -1)]
            t = ''
            while q:
                a, b = q.pop()
                w.add(a)
                if len(d[a]) > 2:
                    ew = 1
                    break
                w1 = [i for i in d[a]]
                if t == '':
                    if len(w1) == 2:
                        t = w1[0] + a + w1[1]
                    else:
                        t = a + w1[0]
                else:
                    if b not in w1:
                        ew = 1
                        break
                    if len(w1) == 2:
                            w1.remove(b)
                            x = w1[0]
                            if x in t:
                                ew = 1
                                break
                            else:
                                if a == t[-1]:
                                    t += x
                                else:
                                    t = x+t
                for j in w1:
                    if j != b:
                        q.append((j, a))
            if ew == 1:
                break
            e.append(t)
    if ew == 1:
        print('NO')
    else:
        print('YES')
        a = ''.join(i for i in e)
        for i in range(97, 123):
            if chr(i) not in a:
                a += chr(i)
        print(a)