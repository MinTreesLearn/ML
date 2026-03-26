def solve():
    n = int(input())
    a = input()
    ans = 0
    if 'A' not in a:
        return 0
    i = 0
    while a[i] == 'P':
        i += 1
    a = a[i:]
    b = [len(i) for i in a.replace('A',' ').split()]
    if len(b):
        return max(b)
    return 0
for i in range(int(input())):
    print(solve())