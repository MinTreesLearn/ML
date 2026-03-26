import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def binary_trie():
    G0, G1, cnt = [-1], [-1], [0]
    return G0, G1, cnt

def insert(x, l):
    j = 0
    for i in range(l, -1, -1):
        cnt[j] += 1
        if x & pow2[i]:
            if G1[j] == -1:
                G0.append(-1)
                G1.append(-1)
                cnt.append(0)
                G1[j] = len(cnt) - 1
            j = G1[j]
        else:
            if G0[j] == -1:
                G0.append(-1)
                G1.append(-1)
                cnt.append(0)
                G0[j] = len(cnt) - 1
            j = G0[j]
    cnt[j] += 1
    return

n = int(input())
a = list(map(int, input().split()))
ma = max(a)
if not ma:
    ans = 0
    print(ans)
    exit()
G0, G1, cnt = binary_trie()
pow2 = [1]
for _ in range(31):
    pow2.append(2 * pow2[-1])
for i in range(32):
    if ma < pow2[i]:
        l = i - 1
        break
for i in set(sorted(a)):
    insert(i, l)
x = [0]
f = 0
ans = 0
for i in range(l, -1, -1):
    if not f:
        if G0[x[0]] ^ -1 and G1[x[0]] ^ -1:
            ans ^= pow2[i]
            x = [G0[x[0]], G1[x[0]]]
            f = 1
        else:
            x = [max(G0[x[0]], G1[x[0]])]
    else:
        y, z = [], []
        for u in x:
            if G0[u] ^ -1 and G1[u] ^ -1:
                y.append(G0[u])
                y.append(G1[u])
            else:
                z.append(max(G0[u], G1[u]))
        if not len(z):
            ans ^= pow2[i]
            x = y
        else:
            x = z
print(ans)