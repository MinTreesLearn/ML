def solve():
    # process t test-cases
    for _ in range(int(input())):
        # Read input list a and b
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        
        # sort the lists
        a = sorted(a)
        b = sorted(b)

        # print the result
        print(*a)
        print(*b)

solve()