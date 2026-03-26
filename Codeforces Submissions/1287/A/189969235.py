a = int(input())
for i in range(a):
    q = int(input())
    s = input()
    if "A" not in s:
        print(0)
    else:
        w = s.index("A")
        d = []
        e = 0
        for j in range(w, q):
            if s[j] == "A":
                d.append(e)
                e = 0
            else:
                 e += 1
        d.append(e)
        print(max(d))
