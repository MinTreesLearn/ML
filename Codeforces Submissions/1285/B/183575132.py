def solve():
    n = int(input())
    aseq = read_ints()

    acc = [0]
    for ai in aseq:
        acc.append(acc[-1] + ai)

    # print(acc)

    yasser_tastiness = acc[-1]
    ans = min(aseq)
    for i, e in enumerate(aseq):
        if e < 0:
            if i + 1 < len(acc):
                ans = max(ans, acc[i] - acc[0], acc[-1] - acc[i+1])
            else:
                ans = max(ans, acc[i] - acc[0])

    # print(ans)
    return ans < yasser_tastiness



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
