def solve():
    n = int(input())
    seq = input()

    ans = [(seq, 1)]

    def check(k):
        if k == 1:
            ans[0] = (seq, 1)
            return

        seq_copy = list(seq)
        seq_copy = seq[k-1:]
        if (n-k) % 2 == 0:
            seq_copy += seq[:k-1][::-1]
        else:
            seq_copy += seq[:k-1]
        
        ans[0] = min(ans[0], (''.join(seq_copy), k))



    indices = []
    cmin = min(seq)
    for i, e in enumerate(seq):
        if e == cmin:
            indices.append(i+1)

    for idx in indices:
        check(idx)
            
    return ans[0]


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans0, ans1 = solve()
        output.append(ans0)
        output.append(ans1)

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
