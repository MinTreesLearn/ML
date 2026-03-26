test = int(input())
for _ in range(test):
    length = int(input())
    array = list(map(int, input().split()))
    count = 0
    if 0 in array:
        count += array.count(0)
        for i in range(length):
            if array[i] == 0:
                array[i] = 1
    if sum(array) == 0:
        count += 1
    print(count)
