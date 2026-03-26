t = int(input())
for i in range(t):
    a = input()
    b = input()
    c = input()
    for i in range(len(a)):
        if c[i] != a[i] and c[i] != b[i]:
            print("NO")
            break
    else:
        print("YES")