def solve(lsts):

    points = []


    for i in range(len(lsts)):
        points.append((lst[i][0], 0, i))
        points.append((lst[i][1], 1, i))

    points.sort()

    open = set()
    increased = [0] * len(lsts)
    original = 0

    for i in range(len(points)):
        p = points[i]
        if p[1] == 0:
            open.add(p[2])
        else:
            open.remove(p[2])


        if len(open) == 1 and p[1] == 1 and points[i+1][1] == 0 :
            increased[list(open)[0]] += 1

        if len(open) == 1 and p[1] == 0 and points[i+1][1] == 1:
            increased[list(open)[0]] -= 1

        # also keep track of what was the original answer without removing
        if len(open) == 0:
            original += 1

    res = -float('inf')
    for i in range(len(lsts)):
        res = max(res, increased[i])

    return res + original


n = int(input())
for _ in range(n):
    m = int(input())
    lst = []
    for _ in range(m):
        lst.append(list(map(int, input().split())))
    print(solve(lst))