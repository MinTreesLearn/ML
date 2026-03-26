n, m = map(int,input().split())
s = input().split()
t = input().split()
q = int(input())
for z in range(q):
    x = int(input()) - 1
    print(s[x % n] + t[x % m])
