# aabb babb babb babb baba
# bbaa bbaa baaa baba baba
# baba aaba abba abaa abab

for _ in range(int(input())):

    a1 = input()
    a2 = input()
    a3 = input()

    flag = 0

    for i in range(len(a1)):
        if a1[i] != a3[i] and a2[i] != a3[i]:
            flag = 1
            break

    if flag == 1:
        print('NO')

    else:
        print('YES')