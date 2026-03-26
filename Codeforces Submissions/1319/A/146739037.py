from math import ceil
n = int(input())
r = list(map(int,input().split()))
b = list(map(int,input().split()))

if sum(r) == sum(b) == 0 or sum(r) == 0:
    print(-1)

else:
    f = False
    for i in range(n):
        if r[i] != b[i]:
            f = True

    if f:
        bwc = 0
        rwc = 0
        for i in range(n):
            if r[i] == 1 and b[i] == 0:
                rwc+=1
            if r[i] == 0 and b[i] == 1:
                bwc+=1
        if rwc == 0:
            print(-1)
            exit()

        res = ceil((bwc+1) / rwc)
        print(res)


    else:
        print(-1)

