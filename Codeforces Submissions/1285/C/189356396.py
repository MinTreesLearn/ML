from math import lcm
for i in range(int((x := int(input())) ** 0.5), 0, -1):
    if x % i == 0 and lcm(i, x // i) == x:
        print(i, x // i)
        break
