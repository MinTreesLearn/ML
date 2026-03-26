import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, x = map(int, input().split())
    w = list(map(int, input().split()))
    a = max(w)
    if a >= x:
        for i in w:
            if i == x:
                print(1)
                break
        else:
            print(2)
    else:
        print((x+a-1)//a)