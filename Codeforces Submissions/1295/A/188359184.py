t = int(input())

for _ in range(t):
    segments = int(input())

    if segments < 2:
        print("1")
    else:
        rem = segments % 2
        if rem:
            total_ones = segments - 3
            total = "7"+("1"*(total_ones//2))
            print(total)
        else:
            ones = "1"*(segments//2)
            print(ones)
