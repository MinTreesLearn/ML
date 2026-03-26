t = int(input())
while t > 0:
    s = input()
    r = [0]
    r += [i + 1 for i in range(len(s)) if s[i] == 'R']
    r += [len(s) + 1]
    print(max(r[i + 1] - r[i] for i in range(len(r) - 1)))
    t -= 1