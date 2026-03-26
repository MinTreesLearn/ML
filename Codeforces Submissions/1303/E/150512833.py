def f(s, t, I):
    n = len(s)
    m = len(t)
    check = [[0 for j in range(m)] for i in range(m)]
    start = [(0, 0)]
    check[0][0] = 1
    for i in range(n):
        next_s = []
        for i1, i2 in start:
            add = True
            if i1 < I and s[i]==t[i1]:
                add = False
                if i1+i2+1==m:
                    return True
                if check[i1+1][i2]==0:
                    check[i1+1][i2] = 1
                    next_s.append((i1+1, i2))
            if I+i2 < m and s[i]==t[I+i2]:
                add = False
                if i1+i2+1==m:
                    return True
                if check[i1][i2+1]==0:
                    check[i1][i2+1] = 1
                    next_s.append((i1, i2+1))
            if add:
                next_s.append((i1, i2))
        start = next_s
    return False
    
def process(s, t):
    m = len(t)
    for i in range(m):
        if f(s, t, i):
            print('YES')
            return
    print('NO')
    
T = int(input())
for i in range(T):
    s = input()
    t = input()
    process(s, t)