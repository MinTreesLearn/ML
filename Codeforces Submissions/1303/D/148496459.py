import sys

input = lambda: sys.stdin.buffer.readline().decode().strip()
get_bit, sz = lambda x, i: (x >> i) & 1, 47

for _ in range(int(input())):
    n, m = map(int, input().split())
    a, mem, ans = [int(x) for x in input().split()], [0] * sz, 0

    if n > sum(a):
        print(-1)
        continue

    for i in range(m):
        mem[a[i].bit_length() - 1] += 1

    for bit in range(sz - 1):
        cur = get_bit(n, bit)
        if cur:
            if mem[bit]:
                mem[bit] -= 1
            else:
                for j in range(bit + 1, sz):
                    if mem[j]:
                        ans += j - bit
                        mem[j] -= 1
                        break
                    n ^= get_bit(n, j) << j

        mem[bit + 1] += mem[bit] >> 1
    print(ans)
