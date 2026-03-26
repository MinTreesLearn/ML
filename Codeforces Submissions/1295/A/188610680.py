n = int(input())

for i in range(n):
    val = int(input())
    if val%2 == 0:
        print("1"*(val//2))
    else:
        print("7" + "1" * ((val - 3)//2))