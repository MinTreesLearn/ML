def solve():
    a, b, p = read_ints()
    seq = input()

    cost = []
    prev = '$'
    c = 0
    for i, e in enumerate(seq, start=1):
        if e != prev:
            c = a if e == 'A' else b
            cost.append((i, c))
            prev = e

    c = 0
    for i in range(len(cost)-1, -1, -1):
        idx, cur = cost[i]
        if idx == len(seq):
            cur = 0
        c += cur
        cost[i] = (idx, c)

    for idx, c in cost:
        if c <= p:
            return idx

    return len(seq)

    



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
