caseNumber = int(input())

while caseNumber != 0:
    arraySize = int(input())
    array = input().split(" ")
    positionCount = 0
    middlePosition = int(arraySize/2) - 1
    Pass = True
    if arraySize%2 == 0:
            if int(array[middlePosition]) < middlePosition + 1 and int(array[middlePosition + 1]) < middlePosition + 1:
                #print("proc failure")
                Pass = False
    for digit in array:
        #print("assessing " + digit)
        digit = int(digit)
        reversePositionCount = arraySize - 1 - positionCount
        if reversePositionCount < positionCount:
            relativePosition = reversePositionCount
        else:
            relativePosition = positionCount
        #print("relative position: " + str(relativePosition))
        if digit < relativePosition:
            #print("proc failure")
            Pass = False
            break
        positionCount = positionCount + 1
    if Pass == True:
        print("Yes")
    else:
        print("No")
    caseNumber = caseNumber - 1
