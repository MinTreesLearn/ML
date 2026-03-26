tst = int(input()) 
for i in range(tst) :
    arr = list(map(int, input().rstrip().split()))
    arr.sort()
    a, b, c = arr[2], arr[1], arr[0]
    cnt = 0
    if a >= 4 and b >= 4 and c >= 4 :
        print(7)
        continue
    if a > 0 :
        a -= 1
        cnt += 1
    if b > 0 :
        b -= 1
        cnt += 1
    if c > 0 :
        c -= 1
        cnt += 1
    if a > 0 and b > 0:
        a -= 1
        b -= 1
        cnt += 1
    if a > 0 and c > 0:
        a -= 1
        c -= 1
        cnt += 1
    if b > 0 and c > 0 :
        b -= 1
        c -= 1
        cnt += 1
    if a > 0 and b > 0 and c > 0 :
        a -= 1
        b -= 1
        c -= 1
        cnt += 1
    print(cnt)