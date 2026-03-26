for i in range(int(input())):
    s = input()
    while len(s) > 0 and s[0] == "0":
        s = s[1:]
    while len(s) > 0 and s[-1] == "0":
        s = s[:-1]
    res = 0
    for x in s:
        if x == "0":
            res += 1
    print(res)