for _ in range(int(input())):
    line = input()
    s, f = -1, -1
    for i in range(len(line)):
        if line[i] == '1':
            if s < 0:
                s = i
            f = i
    print(line[s:f].count('0'))
