def main():
    t = int(input())
    for _ in range(t):
        _ = int(input())
        a = [int(i) for i in input().split()]
        o, e = 0, 0
        for x in a:
            if x % 2:
                o += 1
            else:
                e += 1
        s = sum(a)
        if s % 2:
            print("YES")
        else:
            if o != 0 and e != 0:
                print("YES")
            else:
                print("NO")


if __name__ == "__main__":
    main()