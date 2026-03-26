import os, sys, io

# switch to fastio
fast_mode = 0
# local file test -> 1, remote test --> 0
local_mode = 0

if local_mode:
    fin = open("./data/input.txt", "r")
    fout = open("./data/output.txt", "w")
    sys.stdin = fin
    sys.stdout = fout

if fast_mode:
    input = io.BytesIO(os.read(sys.stdin.fileno(), os.fstat(0).st_size)).readline  # fast input
    if local_mode:
        fin = open("./data/input.txt", "br")  # binary mode
        input = io.BytesIO(fin.read()).readline  # for local file
else:
    input = lambda: sys.stdin.readline().rstrip("\r\n")  # normal mode

stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
ssw = sys.stdout.write


def ini():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def instr():
    s = input().decode().rstrip("\r\n") if fast_mode else input()
    return list(s)


# main code
def solve():
    for ii in range(ini()):
        n = ini()
        a = inlt()
        a.sort(reverse=True)
        print(*a)


if __name__ == '__main__':
    solve()
    os.write(sys.stdout.fileno(), stdout.getvalue())  # final output

    if local_mode:
        fin.close()
        fout.close()