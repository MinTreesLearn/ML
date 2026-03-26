from collections import Counter

def main():
    n = int(input())
    bseq = read_ints()
    
    res = Counter()
    for i, e in enumerate(bseq):
        res[e - i] += e

    ans = max(res.values())
    print(ans)


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
