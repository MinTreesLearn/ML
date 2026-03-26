t = int(input())

def test(numbers):
    # ood number exist
    odd_exists = False 

    # even number exists
    even_exists = False
    
    for number in numbers:
        if number % 2 == 0:
            even_exists = True
        else:
            odd_exists = True

    if odd_exists and even_exists:
        return True
    elif odd_exists and not even_exists:
        if len(numbers) % 2 != 0:
            return True
        else:
            return False
    else:
        return False 

for _ in range(t):
    n = int(input())
    numbers = tuple(map(int, input().split()))
    if test(numbers):
        print('YES')
    else:
        print('NO')
