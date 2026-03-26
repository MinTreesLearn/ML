t = int(input())
for i in range(t):
    s = input()
    if len(s) <= 2:
        print(0)
    else:

        first_index = 0
        for i in range(len(s)):
            if s[i] == '1':
                first_index = i
                break
        last_index = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '1':
                last_index = i
                break

        c = 0
        for i in range(first_index + 1, last_index):
            if s[i] == '0':
                c = c + 1

        print(c)
