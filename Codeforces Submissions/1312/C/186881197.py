def solve():
    n, k = read_ints()
    aseq = read_ints()

    amax = max(aseq)
    length = 0
    while amax > 0:
        amax //= k
        length += 1

    all_powers = []
    for i, ai in enumerate(aseq):
        ai_copy = ai
        powers = []
        while ai_copy > 0:
            powers.append(ai_copy % k)
            ai_copy //= k

        powers += [0] * (length - len(powers))

        powers = powers[::-1]
        all_powers.append(powers)

    for i in range(length):
        cnt = 0
        for powers in all_powers:
            if powers[i] > 1:
                return False
            elif powers[i] == 1:
                cnt += 1

        if cnt > 1:
            return False

    return True

            

    return True


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans = solve()
        output.append('YES' if ans else 'NO')

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
