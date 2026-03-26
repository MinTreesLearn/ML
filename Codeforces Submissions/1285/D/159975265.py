def find_min(num_list, pos):
    if pos < 0:
        return 0
    zeros = []
    ones = []
    for num in num_list:
        if num >> pos & 1 == 0:
            zeros.append(num)
        else:
            ones.append(num)
    if len(zeros) == 0:
        return find_min(ones, pos-1)
    if len(ones) == 0:
        return find_min(zeros, pos-1)
    return min(find_min(zeros, pos - 1), find_min(ones, pos - 1)) + (1 << pos)

n = int(input())
numbers = list(map(int, input().split()))
pos = 30
print(find_min(numbers, pos))