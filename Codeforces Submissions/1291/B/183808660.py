def solve():
    n = int(input())
    aseq = read_ints()

    last = aseq[0]
    last_idx = 0
    for i in range(n):
        if aseq[i] >= i:
            last = aseq[i]
            last_idx = i
        else:
            break

    # print(last, last_idx)
    # print(aseq)


    for i in range(last_idx+1, n):
        # print(aseq[i], last-1)
        if aseq[i] >= aseq[i-1]:
            if aseq[i-1] - 1 < 0:
                return False

            aseq[i] = aseq[i-1] - 1

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
