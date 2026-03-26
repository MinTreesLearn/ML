def main():
    n = int(input())
    seq = input()

    bopened = seq.count('(')
    bclosed = n - bopened
    if bopened != bclosed:
        print(-1)
        return

    cnt = 0
    opened = closed = 0
    bad = False
    for e in seq:
        if e == '(':
            opened += 1
        else:
            closed += 1

        if closed > opened:
            bad = True
            cnt += 1
        elif closed == opened and bad:
            bad = False
            cnt += 1
        else:
            bad = False



    print(cnt)





def read_ints(): return [int(c) for c in input().split()]
def print_lines(lst): print('\n'.join(map(str, lst)))


if __name__ == "__main__":
    from os import environ as env
    if 'COMPUTERNAME' in env and 'L2A6HRI' in env['COMPUTERNAME']:
        import sys
        sys.stdout = open('out.txt', 'w')
        sys.stdin = open('in.txt', 'r')

    main()
