def solve():
    n, m = read_ints()
    seq = input()
    pseq = read_ints()

    a = ord('a')
    accs = [[0] * 26 for _ in range(n+1)]
    for i, c in enumerate(seq):
        for j in range(26):
            accs[i+1][j] = accs[i][j]
            if j == ord(c) - a:
                accs[i+1][ord(c)-a] += 1

    res = [0] * 26
    for i, pi in enumerate(pseq):
        for j in range(26):
            res[j] += accs[pi][j]

    for c in seq:
        res[ord(c)-a] += 1

    print(*res)


def main():
    t = int(input())
    for _ in range(t):
        solve()


def read_ints(): return [int(c) for c in input().split()]
def print_lines(lst): print('\n'.join(map(str, lst)))


if __name__ == "__main__":
    from os import environ as env
    if 'COMPUTERNAME' in env and 'L2A6HRI' in env['COMPUTERNAME']:
        import sys
        sys.stdout = open('out.txt', 'w')
        sys.stdin = open('in.txt', 'r')

    main()
