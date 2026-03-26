def main():
    t = int(input())
    for _ in range(t):
        a, b, c, n = [int(i) for i in input().split()]
        mx = max(a, b, c)
        diff = 0
        for k in [a, b, c]:
            diff += abs(k - mx)
        if n >= diff and (n - diff) % 3 == 0:
            print("YES")
        else:
            print("NO")
        

if __name__ == "__main__":
    main()