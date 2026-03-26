# LUOGU_RID: 101844928
for _ in range(int(input())):
    n = int(input())
    s = input()
    a = [0] * n
    for i in range(1, n):
        if s[i-1:i+1] == 'AP':
            a[i] = 1
        elif a[i - 1] and s[i] != 'A':
            a[i] = a[i - 1] + 1
    print(max(a))
