def solve():
    n = int(input())
    seq = input()

    min_indices = []
    cmin = min(seq)
    for i, e in enumerate(seq):
        if e == cmin:
            min_indices.append(i)

    res = (seq, 1)
    for idx in min_indices:
        head = seq[idx:]
        tail = seq[:idx]
        if (n - idx) % 2 == 1:
            tail = tail[::-1]

        proc_seq = ''.join(head + tail)
        res = min(res, (proc_seq, idx+1))

    return res


def main():
    t = int(input())
    output = []
    for _ in range(t):
        seq, k = solve()
        output.append(seq)
        output.append(k)

    print_lines(output)


def input(): return next(test).strip()
def read_ints(): return [int(c) for c in input().split()]
def print_lines(lst): print('\n'.join(map(str, lst)))


if __name__ == "__main__":
    import sys
    from os import environ as env
    if 'COMPUTERNAME' in env and 'L2A6HRI' in env['COMPUTERNAME']:
        sys.stdout = open('out.txt', 'w')
        sys.stdin = open('in.txt', 'r')

    test = iter(sys.stdin.readlines())

    main()
