t = int(input())
for _ in range(t):
    n = int(input())
    num = list(map(int, input().split()))
    num.sort()
    num = num[::-1]
    num = list(map(str, num))
    print(" ".join(num))