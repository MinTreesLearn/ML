def solve():
    n,m = list(map(int,input().split()))
    return min(sum(list(map(int,input().split()))),m)
for i in range(int(input())):
    print(solve())