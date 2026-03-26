import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        ev = 0
        ods = []
        for i in range(n):
            if (a[i] & 1) == 0:
                ev = i + 1
            else:
                ods.append(i + 1)

        if ev != 0:
            print(1)
            print(ev)
        elif len(ods) >= 2:
            print(2)
            print(ods[0], ods[1])
        else:
            print(-1)








main()
