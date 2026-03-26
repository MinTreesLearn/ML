inf = int(2e9) + 1

n = int(input())
m = [-inf] + [int(x) for x in input().split()] + [-inf]

def get_lmin():
    l = [0] * (n + 2)
    st = [n + 1]
    for i in range(n, -1, -1):
        while m[st[-1]] > m[i]:
            l[st.pop()] = i
        st.append(i)
    return l


def get_rmin():
    r = [0] * (n + 2)
    st = [0]
    for i in range(1, n + 2):
        while m[st[-1]] > m[i]:
            r[st.pop()] = i
        st.append(i)
    return r


lmin = get_lmin()
rmin = get_rmin()
l = [0] * (n + 2)
r = [0] * (n + 2)


maximum = 0
t = 0

for i in range(1, n + 1):
    if lmin[i] == 0:
        l[i] = i * m[i]
    else:
        j = lmin[i]
        l[i] = l[j] + (i - j) * m[i]
        
for i in range(n, 0, -1):
    if rmin[i] == n + 1:
        r[i] = (n - i + 1) * m[i]
    else:
        j = rmin[i]
        r[i] =  r[j] + (j - i) * m[i]

for i in range(1, n + 1):
    if l[i] + r[i] - m[i] > maximum:
        maximum = l[i] + r[i] - m[i]
        t = i

ans = [0] * n
ans[t - 1] = m[t]

for i in range(t - 1, 0, -1):
    if m[i] <= ans[i]:
        ans[i - 1] = m[i]
    else:
        ans[i - 1] = ans[i]

for i in range(t + 1, n + 1):
    if ans[i - 2] >= m[i]:
        ans[i - 1] = m[i]
    else:
        ans[i - 1] = ans[i - 2]
print(' '.join(map(str, ans)))
