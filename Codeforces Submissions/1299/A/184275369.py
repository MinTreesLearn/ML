


def solve():
    num_values = int(input())
    values = [int(each) for each in input().split()]
    if num_values == 1:
        print(values[0])
        return
    right_and = [values[0]]
    left_and = [values[-1]]
    for i in range(1, num_values):
        right_and.append(values[i]|right_and[-1])
    for i in range(num_values-2, -1, -1):
        left_and.append(values[i]|left_and[-1])
    left_and = list(reversed(left_and))

    best = values[0]&(~left_and[1])
    best_value = values[0]
    right = values[-1]&(~right_and[-2])
    if right > best:
        best = right
        best_value = values[-1]

    for i in range(1, num_values - 1):
        curr_value = values[i]
        curr_best = curr_value&(~(right_and[i-1]|left_and[i+1]))
        if curr_best > best:
            best = curr_best
            best_value = curr_value

    new_values = [best_value]
    flag = False
    for each in values:
        if flag or each != best_value:
            new_values.append(each)
        else:
            flag = True
    
    print(" ".join([str(each) for each in new_values]))
solve()