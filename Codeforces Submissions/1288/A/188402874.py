from math import ceil
for _ in range(int(input())):
    n, d = map(int, input().split())
    if d <= n:
        print("YES")
    else:
        low = 0
        high = n
        flag = False
        while low <= high:
            mid = (low + high) // 2
            time = mid + ceil(d / (mid + 1))
            if time <= n:
                flag = True
                break
            else:
                high = mid - 1
        if flag:
            print("YES")
        else:
            print("NO")
