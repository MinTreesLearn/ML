for _ in range(int(input())):
    n = int(input())
    m, t = 0, 0
    a = input()
    if n == 1 or len(set(a)) == 1:
        print(0)
        continue
    j = a.index('A')
    for i in range(j + 1, n):
        if a[i] == 'P':
            t += 1
        else:
            m = max(m, t)
            t = 0
    print(max(m, t))