#from highlight import *
t = int(input())

for _ in range(t):
    res = float("inf")
    triple = []

    a, b, c = map(int, input().split())
    for af in range(1, 2*a+1):
        for bf in range(af, 2*b+1, af):
            for cf in [c//bf*bf, c//bf*bf+bf]:
                if af <= bf <= cf and abs(af-a) + abs(bf-b) + abs(cf-c) < res:
                    res = abs(af-a) + abs(bf-b) + abs(cf-c)
                    triple = [af, bf, cf]
    
    print(res)
    print(triple[0], triple[1], triple[2])