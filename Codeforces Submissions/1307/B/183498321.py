def solve():
    n, x = read_ints()
    aseq = read_ints()
    if x in aseq:
        return 1

    amax = max(aseq)
    if amax > x:
        return 2

    ans = 0--x // amax

    return ans


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans = solve()
        output.append(ans)

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
