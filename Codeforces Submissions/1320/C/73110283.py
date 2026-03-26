from sys import stdin, stdout
from bisect import bisect_left, bisect_right

dp = []
add = []
am = []

def build(pos, l,r):
    global dp
    global am
    if l == r - 1:
        dp[pos] = -am[l][1]
        return
    mid = int((l+r)/2)
    build (pos*2+1,l,mid)
    build (pos*2+2,mid,r)
    dp[pos] = max(dp[pos*2+1],dp[pos*2+2])
    
def push(pos, l,r):
    global dp
    global add
    if add[pos] != 0:
        if r- l > 1:
            add[pos*2+1] += add[pos]
            dp[pos*2+1] += add[pos]
            add[pos*2+2] += add[pos]
            dp[pos*2+2] += add[pos]
        add[pos] = 0
    
def update(pos, l,r,L,R, val):
    global dp
    global add
    if L>=R:
        return
    if l == L and r == R:
        add[pos] += val
        dp[pos] += val
        push(pos, l,r)
        return
    push(pos, l,r)
    mid = int((l+r)/2)
    update(pos*2+1, l, mid, L, min(R,mid), val)
    update(pos*2+2, mid, r, max(L,mid), R, val)
    dp[pos] = max(dp[pos*2+1],dp[pos*2+2])
     
def main():
    global dp
    global am
    global add
    n,m,k = list(map(int, stdin.readline().split()))
    AMT = 1000002
    dp = [0] * (m *4 + 2)
    add = [0] * (m *4 + 2)
    WP = [-1] * AMT
    AM = [-1] * AMT
    am2 = []
    PWN = [[] for _ in range(AMT)]
    max_atk = -1
    for _ in range(n):
        power, cost = list(map(int, stdin.readline().split()))
        if WP[power] == -1 or (WP[power] != -1 and WP[power] > cost):
            WP[power] = cost
            if power > max_atk:
                max_atk = power
    
    for _ in range(m):
        power, cost = list(map(int, stdin.readline().split()))
        if AM[power] == -1 or (AM[power] != -1 and AM[power] > cost):
            AM[power] = cost
            
    for _ in range(k):
        atk, df, gold =  list(map(int, stdin.readline().split()))
        PWN[atk+1].append((df, gold))
    for i in range(AMT):
        if AM[i] != -1:
            am.append((i, AM[i]))
            am2.append(i)
    m = len(am)

    build(0,0,m)
    mx = -999999999999
    for i in range(AMT):
        if i > max_atk:
            break
        for a,b in PWN[i]:
            right = bisect_right(am2, a)
            update(0, 0, m, right, m, b)
        if WP[i] == -1:
            continue
        temp = dp[0]
        if  temp - WP[i] > mx:
            mx = temp - WP[i]
    stdout.write(str(mx))

main()