import sys
latin = "abcdefghijklmnopqrstuvwxyz"
n = int(input())
if n == 1:
    print("?", 1, n)
    sys.stdout.flush()
    a = input()
    print("!", a)
else:
    print("?",1,n)
    sys.stdout.flush()
    d1 = {}
    for i in range(1,n+1):
        d1[i] = []
    for i in range((n+1)*n//2):
        s = input()
        dick = []
        for i in latin:
            dick.append(s.count(i))
        d1[len(s)].append(dick)
    print("?",2,n)
    sys.stdout.flush()
    d2 = {}
    for i in range(1,n):
        d2[i] = []
    for i in range((n-1)*n//2):
        s = input()
        dick = []
        for i in latin:
            dick.append(s.count(i))
        d2[len(s)].append(dick)
    odp = [0] * n
    for i in range(1,n+1):
        d1[i].sort()
        if i < n:
            d2[i].sort()
    lewe = {}
    for i in range(1, n):
        kandydat = d1[i][-1]
        for j in range(len(d2[i])):
            if d1[i][j] != d2[i][j]:
                kandydat = d1[i][j]
                break
        lewe[i] = kandydat
    lewe[n] = d1[n][0]
    for i in range(26):
        if lewe[1][i] !=0:
            odp[0] = chr(97+i)
    for i in range(2, n+1):
        for j in range(26):
            if lewe[i][j] > lewe[i-1][j]:
                odp[i-1] = chr(97 + j)
    print("!","".join(odp))