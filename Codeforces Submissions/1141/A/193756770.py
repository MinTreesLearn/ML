a = input().split()
b = int(a[1])
a = int(a[0])
if a == b: print("0")
elif b % a != 0 or (b / a % 2 != 0 and b / a % 3 != 0): print("-1")
else:
    b /= a
    count = 0
    while b % 2 == 0: 
        b /= 2
        count += 1
    while b % 3 == 0:
        b /= 3
        count += 1
    if b != 1: print("-1") 
    else: print(count)