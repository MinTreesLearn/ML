def solve():

    t = int(input())

    for i in range(t):

        n = int(input())
        b = list(map(int, input().split()))

        impossible = False
        a = [-1] * (2 * n)
        numbers = set(b)

        for i, x in enumerate(b):

            if impossible:
                break

            a[2 * i] = x

            bigger = x + 1
            while bigger in numbers:
                bigger += 1

            if bigger <= 2 * n:
                a[2 * i + 1] = bigger
                numbers.add(bigger)

            else:
                impossible = True

        if impossible:
            print("-1")
        else:
            print(" ".join(map(str, a)))


solve()
