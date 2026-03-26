n = [int(_) for _ in input().split()]

a = [_ for _ in input().split()]
b = [_ for _ in input().split()]

for i in range(int(input())):

    s = int(input())
    v1 = s % n[0]
    v2 = s % n[1]
    print(''.join(a[v1-1])+ ''.join(b[v2-1]))
