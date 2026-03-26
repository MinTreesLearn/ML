def main():
    t = int(input())
    anss = [0] * t
    for it in range(t):
        x, y, a, b = map(int, input().split())
        d, m = divmod(y - x, a + b)
        anss[it] = d if m == 0 else -1
    for ans in anss:
        print(ans)


main()
