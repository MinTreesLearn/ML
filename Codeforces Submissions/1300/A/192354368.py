import math

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        nonz = 0
        c = 0
        for i in a:
            if i == 0:
                c+=1
                nonz += 1
            else:
                nonz += i

        if nonz == 0:
            c += 1

        print(c)






main()
