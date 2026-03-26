def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = a.count(0)
    return b + int(sum(a) + b == 0)
for i in range(int(input())):
    print(solve())