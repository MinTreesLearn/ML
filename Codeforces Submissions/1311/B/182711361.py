def solve():
    # First we'd like to get the number of test cases that we'd like to run
    t = int(input())

    # Now let's run a loop to get the input for each testcase
    for i in range(t):
        n, m = list(map(int, input().split(" ")))

        a = list(map(int, input().split(" ")))

        positions = list(
            map(int, input().split(" "))
        )  # these positions would help us sorting the array

        positions.sort()

        # If an array can be sorted it can be sorted in n steps
        for _ in range(n):
            for p in positions:
                if a[p - 1] > a[p]:
                    a[p - 1], a[p] = a[p], a[p - 1]

        if a == sorted(a):
            print("YES")
        else:
            print("NO")


solve()
