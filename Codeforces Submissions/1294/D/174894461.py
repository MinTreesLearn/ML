n, x = map(int, input().split())
arr, result  = [0]*(n), []
mex = 0
for _ in range(n):
    arr[int(input())%x] += 1
    while arr[mex%x]:
        arr[mex%x] -= 1
        mex +=1
    result.append(mex)

print("\n".join(map(str, result)))