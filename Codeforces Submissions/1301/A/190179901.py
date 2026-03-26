a = int(input())
for i in range(a):
    q = input()
    s = input()
    w = input()
    d = "YES"
    for j in range(len(q)):
        if q[j] != w[j] and w[j] != s[j]:
            d = "NO"
            break
    print(d)
