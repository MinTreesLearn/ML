t = int(input())


def max_subarray(arr):
    acc = 0
    min_acc = 0
    max_acc = float("-inf")
    for num in arr:
        acc += num
        max_acc = max(max_acc, acc - min_acc)
        min_acc = min(min_acc, acc)
    return max_acc


for i in range(t):
    n = int(input())
    arr = list(map(int, input().split(" ")))

    print("YES" if sum(arr) > max(max_subarray(arr[1:]), max_subarray(arr[:-1])) else "NO")
