import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int, input().split()))

stk = []
for x in a:
    s = 1.0 * x
    c = 1
    while stk and stk[-1][0] * c >= s * stk[-1][1]:
        s += stk[-1][0]
        c += stk[-1][1]
        stk.pop()
    stk.append((s, c))

sys.stdout.write(''.join('{}\n'.format(s / c) * c for s, c in stk))
