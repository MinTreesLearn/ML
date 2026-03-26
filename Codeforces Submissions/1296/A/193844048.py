for _ in range(int(input())):
    length = int(input())
    odd = 0
    
    for number in input().split():
        if int(number) & 1:
            odd += 1
    
    if odd == 0:
        print('NO')
    elif odd == length and not length & 1:
        print('NO')
    else:
        print('YES')