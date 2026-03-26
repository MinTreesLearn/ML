def solve(n, d, arr):

    i = 1
    while d > 0 and i < n:

        if arr[i] <= 0 or d < i:
            i += 1
        elif d >= i:
            d -= i
            arr[0] += 1
            arr[i] -= 1

    return arr[0]


if __name__ == "__main__":

    t = int(input())

    results = list()
    for _ in range(0, t):
        n, d = list(map(int, input().split(" ")))
        arr = list(map(int, input().split(" ")))
        results.append(solve(n, d, arr))

    for result in results:
        print(result)