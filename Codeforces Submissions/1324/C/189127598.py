t = int(input())
for i in range(t):
    s = input()
    s = list(s.split('R'))
    maxim = 0
    for i in s:
        if len(i) > maxim:
            maxim = len(i)
    print(maxim + 1)