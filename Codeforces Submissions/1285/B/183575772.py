def solve():
    n = int(input())
    aseq = read_ints()

    acc1 = acc2 = 0
    for i in range(n-1):
        acc1 += aseq[i]
        acc2 += aseq[n-i-1]
        if acc1 <= 0 or acc2 <= 0:
            return False

    return True


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans = solve()
        output.append('YES' if ans else 'NO')

    print_lines(output)


def read_ints(): return [int(c) for c in input().split()]
def print_lines(lst): print('\n'.join(map(str, lst)))


if __name__ == "__main__":
    from os import environ as env
    if 'COMPUTERNAME' in env and 'L2A6HRI' in env['COMPUTERNAME']:
        import sys
        sys.stdout = open('out.txt', 'w')
        sys.stdin = open('in.txt', 'r')

    main()
