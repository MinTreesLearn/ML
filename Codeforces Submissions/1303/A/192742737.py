t = int(input())
A = []
for i in range (t):
    a = str(input())
    A.append(a)
for i in range (t):
    s = A[i]
    gas = False
    if "1" not in s or s.count("1") == 1:
        print(0)
    else:
        x = s.index("1")
        y = s[::-1].index("1")
        print(s[x:(len(s) - y)].count("0"))