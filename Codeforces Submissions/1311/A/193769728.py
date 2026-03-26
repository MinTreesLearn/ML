def main():
    t = int(input())
    # Loop through each test case and compute
    for _ in range(t):
        a, b = [int(i) for i in input().split()]
        if a == b:
            print(0)
            continue
        diff = abs(a-b)
        if diff % 2:
            if a < b:
                print(1)
            else:
                print(2)
        else:
            if a < b:
                print(2)
            else:
                print(1)
    

if __name__ == "__main__":
    main()