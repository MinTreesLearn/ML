def ri(): return int(input())
def rs(): return input()
def rl(): return list(map(int, input().split()))
def rls(): return list(input().split())


def main():
    n = ri()
    a = rl()

    def rec(a, x):
        if not len(a) or x < 0:
            return 0
        on = [i for i in a if i & (1 << x)]
        of = [i for i in a if not i & (1 << x)]
        if not len(on):
            return rec(of, x-1)
        if not len(of):
            return rec(on, x-1)
        return (1 << x) + min(rec(on, x-1), rec(of, x-1))

    print(rec(a, 30))
    pass


main()
