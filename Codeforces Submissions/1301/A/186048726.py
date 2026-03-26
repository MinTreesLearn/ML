def solve():
    a = input()
    b = input()
    c = input()
    for i in range(len(a)):
        if c[i] not in [a[i],b[i]]:
            return 'NO'
    return 'YES'
for i in range(int(input())):
    print(solve())