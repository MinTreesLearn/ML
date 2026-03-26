#! /bin/env python3

# please follow ATshayu

def main():
    n, a, b, k = map(int, input().split(' '))
    h = map(int, input().split(' '))
    # solve
    def ceil(a, b): return a//b if a%b == 0 else a//b+1
    res = []
    ans = 0
    for ele in h:
        x, r = ele//(a+b), ele%(a+b)
        if r == 0: x -= 1
        if 1 <= r and r <= a:
            ans += 1
            continue
        r = ele - x*(a+b) - a
        res.append(ceil(r, a))
    res.sort()
    for ele in res:
        if ele > k: break
        ans += 1
        k -= ele
    print(ans)

main()