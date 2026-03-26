# https://codeforces.com/problemset/problem/1294/B

test_cases = int(input())


def handle():
    lines = int(input())
    points = []

    for _ in range(lines):
        x, y = input().split(" ")
        x = int(x)
        y = int(y)

        points.append((x, y))

    points.sort()
    y_so_far = points[0][1]

    for x, y in points[1:]:
        if y < y_so_far:
            return ["NO"]
        y_so_far = y

    current_x = 0
    current_y = 0
    path = ""

    for x, y in points:
        while current_x != x:
            path += "R"
            current_x += 1
        while current_y != y:
            path += "U"
            current_y += 1

    return ["YES", path]


for _ in range(test_cases):
    result = handle()
    for line in result:
        print(line)
