n = int(input())
arr = list(map(ord,list(input())))
for i in range(n):
    arr[i]-=97
for i in range(26,-1,-1):
    deleted = True
    while (deleted):
        delHere = False

        for g in range(len(arr)):
            if arr[g] == i:
                if g != 0:
                    if arr[g-1] == i-1:
                        arr.pop(g)
                        delHere = True
                        break
                if (g != len(arr) -1 ):
                    if arr[g+1] == i-1:
                        arr.pop(g)
                        delHere = True
                        break
        deleted = delHere
print(n-len(arr))
