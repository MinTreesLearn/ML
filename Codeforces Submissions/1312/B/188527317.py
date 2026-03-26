t = int(input())
for _ in range(t):
    n = input()
    a = list(map(lambda x: int(x), input().split()))
    a.sort()
    a = list(reversed(a))
    for i in a:print(i , end=" " if len(a) > 1 else "")
    print("")
