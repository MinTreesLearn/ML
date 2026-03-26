for _ in range(int(input())):
    n = int(input())
    if n <= 3:
        if n == 3:
            print(7)
        else:
            print(1)
    else:
        if n % 2 == 0:
            print('1' * (n // 2))
        else:
            print('7' + ('1' * ((n - 3) // 2)))