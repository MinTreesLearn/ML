n = int(input())
arr = list(map(int,input().split()))

lowerBound = [(0,0), (1,arr[0])]
currSum = arr[0]
for i in range(1,n):
    currSum += arr[i]
    xcoord = i+1
    ycoord = currSum
    while (len(lowerBound) > 1) and ( (ycoord - lowerBound[-1][1]) / (xcoord - lowerBound[-1][0]) <= (ycoord - lowerBound[-2][1]) / (xcoord - lowerBound[-2][0]) ):
        lowerBound.pop()
    lowerBound.append((xcoord,ycoord))

ans = []
for i in range(1,len(lowerBound)):
    xdiff = lowerBound[i][0] - lowerBound[i-1][0]
    ydiff = lowerBound[i][1] - lowerBound[i-1][1]
    avg = ydiff / xdiff 
    for j in range(xdiff):
        ans.append(avg)
print(*ans)