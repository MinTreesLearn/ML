def main():
    t = int(input())
    anss = [False] * t
    for it in range(t):
        n, m = map(int, input().split())
        anss[it] = n % m == 0
    for ans in anss:
        print('YES' if ans else 'NO')


main()
