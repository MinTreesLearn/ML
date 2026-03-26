for i in range(int(input())):
    l = input().split("R")
    l.sort()
    print(len(l[-1])+1)