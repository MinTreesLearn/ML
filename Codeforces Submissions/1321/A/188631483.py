import math

length = int(input())

first = list(map(int, input().split()))
second = list(map(int, input().split()))

second_count = sum(second)
first_count = sum(first)

if second_count == len(second):
    print(-1)
else:
    intersection_count = 0
    i = 0
    while i < len(first):
        if first[i] == 1 and second[i] == 1:
            intersection_count += 1
        i += 1
    if intersection_count == first_count:
        print(-1)
        exit()

    first_count -= intersection_count
    second_count -= intersection_count
    result = (second_count+1)/first_count

    minumum = math.ceil(result)

    print(minumum)
