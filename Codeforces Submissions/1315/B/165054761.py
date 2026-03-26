def check(sr, w, a, b, p):
    count = 0
    while w != len(sr) - 1:
        if sr[w] == "A" and w != len(sr) - 1:
            count += a
            while w != len(sr) - 1 and sr[w] == "A":
                w += 1
        if s[w] == "B" and w != len(sr) - 1:
            count += b
            while  w != len(sr) - 1 and s[w] == "B":
                w += 1
#    print(count)
    return count > p



for _ in range(int(input())):
    a, b, p = map(int, input().split())
    s = input()
    l = -1
    r = len(s)
#    print(a, "LOL")
    while r - l > 1:
        m  = (r + l) // 2
#        print(l, r, m)
        if check(s, m, a, b, p):
            l = m
        else:
            r = m
    print(r + 1)