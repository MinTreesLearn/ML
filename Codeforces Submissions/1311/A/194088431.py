for i in range(int(input())):
    a,b = map(int,input().split())
    if a == b:
        print(0)
    else:
        print(1 + int((a < b) ^ ((b - a) & 1)))