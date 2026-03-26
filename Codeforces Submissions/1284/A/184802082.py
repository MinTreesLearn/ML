n, m = map(int, input().split())
s = input().split()
t = input().split()

for _ in range(int(input())):
    y = int(input())
    print(s[y%n-1], end="")
    print(t[y%m-1])