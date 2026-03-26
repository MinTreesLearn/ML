import sys
input=sys.stdin.buffer.readline
n, m = map(int, input().split())
a = [int(i) - 1 for i in input().split()]
ans1 = [i + 1 for i in range(n)]
ans2 = [-1 for i in range(n)]
for i in set(a):
    ans1[i] = 1
N = 1
while N < n + m: N <<= 1
st = [0 for i in range(N << 1)]
pos = [i + m for i in range(n)]
for i in range(n):
    st[i + N + m] = 1
for i in range(N - 1, 0, -1):
    st[i] = st[i << 1] + st[i << 1 | 1]
def up(i,v):
    i+=N
    st[i]=v
    i>>=1
    while(i>0):
        st[i]=st[i<<1]+st[i<<1|1]
        i>>=1

def qr(l,r=N):
    l+=N
    r+=N
    add=0
    while(l<r):
        if l&1:
            add+=st[l]
            l+=1
        if(r&1):
            add+=st[r]
            r-=1
        l>>=1
        r>>=1
    return add



for j in range(m):
    x = a[j]
    i = pos[x]
    ans2[x] = max(ans2[x], n - qr(i + 1))
    up(i, 0)
    pos[x] = m - 1 - j
    up(pos[x], 1)

for i in range(n):
    x = pos[i]
    ans2[i] = max(ans2[i], n - qr(x + 1))
for i in range(n):
    print(ans1[i], ans2[i])

