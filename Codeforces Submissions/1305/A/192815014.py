for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    print(*A)
    print(*B)