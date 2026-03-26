def solve():
    n = int(input())
    aseq = read_ints()

    i = peak = 0
    while i < n and aseq[i] >= i:
        peak = i
        i += 1

    prev = aseq[peak]
    for i in range(peak+1, n):
        if aseq[i] >= prev:
            if prev - 1 < 0:
                return False

            prev -= 1
        else:
            prev = aseq[i]

    return True


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans = solve()
        output.append('Yes' if ans else 'No')

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
