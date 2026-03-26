import sys
input = sys.stdin.readline
n,q = map(int,input().split())
lava = set()
cnt = 0
for _ in range(q):
    r,c = map(int,input().split())
    if (r,c) not in lava:
        l = [(r-1,c),(r+1,c),(r-1,c+1),(r+1,c+1),(r-1,c-1),(r+1,c-1)]
        flag = 0
        z = 0
        for x in l:
            if x in lava:
                flag = 1
                z += 1

        lava.add((r,c))
        if not flag:
            if cnt == 0:
                sys.stdout.write(str("Yes\n"))

            else:
                sys.stdout.write(str("No\n"))

        else:
            sys.stdout.write(str("No\n"))
            cnt += z

    else:
        l = [(r - 1, c), (r + 1, c), (r - 1, c + 1), (r + 1, c + 1), (r - 1, c - 1), (r + 1, c - 1)]
        flag = 0
        z = 0
        for x in l:
            if x in lava:
                flag = 1
                z += 1

        if flag:
            cnt -= z

        lava.remove((r,c))
        if cnt == 0:
            sys.stdout.write(str("Yes\n"))

        else:
            sys.stdout.write(str("No\n"))