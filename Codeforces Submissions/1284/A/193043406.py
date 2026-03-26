# LUOGU_RID: 101844461
n, m = map(int, input().split())
s = input().split()
t = input().split()
for _ in range(int(input())):
    x = int(input()) - 1
    print(s[x % n] + t[x % m])