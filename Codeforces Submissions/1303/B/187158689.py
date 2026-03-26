def solve():
    n, g, b = read_ints()

    good_needed = 0--n // 2
    loops = 0--good_needed // g

    cnt = (loops - 1) * (g + b)
    diff = good_needed - (loops - 1) * g
    cnt += diff
    if cnt < n:
        cnt = n
    return cnt
    
    

    


def main():
    t = int(input())
    output = []
    for _ in range(t):
        ans = solve()
        output.append(ans)

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
