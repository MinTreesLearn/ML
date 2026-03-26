_ = int(input())
for i in range(_):
    maxList = [0]
    maxL = 0
    a = str(input())
    for j in a:
        if j == "L":
            maxL += 1
        else:
            maxList.append(maxL)
            maxL = 0
    maxList.append(maxL)
    maxL = max(maxList)
    print(maxL+1)



