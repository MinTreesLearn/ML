t = int(input())

for _ in range(t):
    s = str(input())
    res = 0
    curr = 0
    flag = False
    for i in s:
        if i == "1" and not flag:
            flag = True
        elif i == "0" and flag:
            curr += 1
        elif i == "1":
            res += curr
            curr = 0
    print(res)