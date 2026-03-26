for i in range(int(input())):

    n = int(input())
    arr = [int(_) for _ in input().split()]

    val = 0
    val += arr.count(0)

    if arr.count(0) > 0:

        if sum(arr) + val == 0:
            val += 1

    if sum(arr) + val == 0:
        val += 1

    print(val)

