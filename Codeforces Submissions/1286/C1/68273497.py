from collections import Counter
DEBUG = False

N = int(input())
if N == 1:
    print('? 1 {}'.format(N), flush = True)
    print('! ' + input(), flush = True)
else:
    LC = [Counter() for _ in range(N+1)]
    if not DEBUG:
        print('? 1 {}'.format(N), flush = True)
        for _ in range(N*(N+1)//2):
            K = list(map(lambda x: ord(x)-97, input().strip()))
            l = len(K)
            for k in K:
                LC[l][k] += 1
    else:
        for i in range(1, N+1):
            for j in range(i):
                K = list(map(lambda x: ord(x)-97, S[j:i]))
                l = len(K)
                for k in K:
                    LC[l][k] += 1
    
    comp = [Counter() for _ in range(N+1)]
    pre = Counter()
    for k in range(26):
        comp[N][k] += LC[N][k]
        pre[k] += LC[N][k]
    for x in range(N-1, 0, -1):
        if N+1-x > x:
            break
        for k in range(26):
            comp[x][k] = LC[x][k] - pre[k]
            pre[k] += comp[x][k]
    
    LC2 = [Counter() for _ in range(N)]
    Ar = [None] * (N+1)
    if not DEBUG:
        print('? 1 {}'.format(N-1), flush = True)
        for _ in range((N-1)*N//2):
            K = list(map(lambda x: ord(x)-97, input().strip()))
            l = len(K)
            for k in K:
                LC2[l][k] += 1
    else:
        for i in range(1, N):
            for j in range(i):
                K = list(map(lambda x: ord(x)-97, S[j:i]))
                l = len(K)
                for k in K:
                    LC2[l][k] += 1
    
    comp2 = [Counter() for _ in range(N+1)]
    pre = Counter()
    for k in range(26):
        comp2[N-1][k] += LC2[N-1][k]
        pre[k] += LC2[N-1][k]
    for x in range(N-2, 0, -1):
        if N-x > x:
            break
        for k in range(26):
            comp2[x][k] = LC2[x][k] - pre[k]
            pre[k] += comp2[x][k]

    for i in range(N-1, -1, -1):
        if comp2[i] == Counter():
            break
        for st in range(26):
            if comp[i][st] != comp2[i][st]:
                Ar[N-i] = st
    for i in range(1, N):
        if comp[N+1-i] == Counter():
            break
        for st in range(26):
            if comp[N+1-i][st] != comp2[N-i][st]:
                Ar[N+1-i] = st
    
    print('! ' + ''.join(map(lambda x:chr(x+97), Ar[1:])), flush = True)
    