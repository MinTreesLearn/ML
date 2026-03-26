import sys, os, io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def get_root(s):
    v = []
    while not s == root[s]:
        v.append(s)
        s = root[s]
    for i in v:
        root[i] = s
    return s

def unite(s, t):
    rs, rt = get_root(s), get_root(t)
    if not rs ^ rt:
        return
    if rank[s] == rank[t]:
        rank[rs] += 1
    if rank[s] >= rank[t]:
        root[rt] = rs
        size[rs] += size[rt]
    else:
        root[rs] = rt
        size[rt] += size[rs]
    cnt[get_root(s)] = min(cnt[rs] + cnt[rt], inf)
    return

def same(s, t):
    return True if get_root(s) == get_root(t) else False

def get_size(s):
    return size[get_root(s)]

n, k = map(int, input().split())
s = list(input().rstrip())
c1 = [0] * (n + 1)
c2 = [0] * (n + 1)
for i in range(1, k + 1):
    c = int(input())
    x = list(map(int, input().split()))
    for j in x:
        if not c1[j]:
            c1[j] = i
        else:
            c2[j] = i
root = [i for i in range(2 * k + 1)]
rank = [1 for _ in range(2 * k + 1)]
size = [1 for _ in range(2 * k + 1)]
cnt = [0] * (2 * k + 1)
for i in range(1, k + 1):
    cnt[i] = 1
ans = []
ans0 = 0
inf = pow(10, 9) + 1
for u, v, w in zip(c1[1:], c2[1:], s):
    if u:
        ans0 -= min(cnt[get_root(u)], cnt[get_root(u + k)])
    if v and not same(u, v) and not same(u, v + k):
        ans0 -= min(cnt[get_root(v)], cnt[get_root(v + k)])
    if w & 1 and u:
        if not v:
            cnt[get_root(u)] = inf
        else:
            unite(u, v)
            unite(u + k, v + k)
    elif not w & 1 and u:
        if not v:
            cnt[get_root(u + k)] = inf
        else:
            unite(u, v + k)
            unite(u + k, v)
    if u:
        ans0 += min(cnt[get_root(u)], cnt[get_root(u + k)])
    ans.append(ans0)
for i in range(n - 2, -1, -1):
    ans[i] = min(ans[i], ans[i + 1])
sys.stdout.write("\n".join(map(str, ans)))