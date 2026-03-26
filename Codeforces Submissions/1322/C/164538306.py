import sys
input = sys.stdin.buffer.readline 




def gcd(a, b):
    if a > b:
        a, b = b, a
    if b % a==0:
        return a
    return gcd(b % a, a)


t = int(input())
for i in range(t):
    n, m = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]
    G = []
    for j in range(m):
        u, v = [int(x) for x in input().split()]
        G.append([u, v])
    g1 = [0 for i in range(n+1)]
    g2 = [0 for i in range(n+1)]
    if n >= 100:
        p1 = 1039
        p2 = 1489
    else:
        p1 = 13
        p2 = 17
    for u, v in G:
        g1[v] = (g1[v]+pow(2, u, p1)) % p1
        g2[v] = (g2[v]+pow(2, u, p2)) % p2
    p1_list = [0 for i in range(p1)]
    p2_list = [0 for i in range(p2)]
    R = []
    g_final = None
    for v in range(1, n+1):
        x1 = g1[v]
        x2 = g2[v]
        if [x1, x2] != [0, 0]:
            p1_list[x1]+=C[v-1]
            p2_list[x2]+=C[v-1]
    for i in range(p1):
        if p1_list[i] != 0:
            if g_final is None:
                g_final = p1_list[i]
            else:
                g_final = gcd(g_final, p1_list[i])
    for i in range(p2):
        if p2_list[i] != 0:
            if g_final is None:
                g_final = p2_list[i]
            else:
                g_final = gcd(g_final, p2_list[i])
    sys.stdout.write(f'{g_final}\n')
    input()
