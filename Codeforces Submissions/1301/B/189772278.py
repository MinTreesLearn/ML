import sys
import itertools
import math

def isPossible(A, targetVal):
    lowerBound = -(10 ** 18)
    upperBound = 10**18

    for i in range(len(A)):
        if A[i] == -1:
            if i-1 >= 0 and A[i-1] != -1:
                lowerBound = max(lowerBound, A[i-1] - targetVal)
                upperBound = min(upperBound, A[i-1] + targetVal)

            if i+1 < len(A) and A[i+1] != -1:
                lowerBound = max(lowerBound, A[i+1] - targetVal)
                upperBound = min(upperBound, A[i+1] + targetVal)

    if lowerBound <= upperBound:
        return min(upperBound, 10**9)
    else:
        return -1


def main():
    t = int(input())

    while t > 0:
        t -= 1
        N = int(input())
        A = [int(X) for X in input().split()]
        
        LOW = 0

        for i in range(len(A)-1):
            if A[i] != -1 and A[i+1] != -1:
                LOW = max(LOW, abs(A[i] - A[i+1]))

        HIGH = 10**13
        Res = HIGH
        Res_possibleAns = 10**13

        while LOW <= HIGH:
            MID = (LOW+HIGH)//2
            fnEval = isPossible(A, MID)

            if fnEval > -1:
                Res_possibleAns = fnEval
                Res = MID
                HIGH = MID-1
            else:
                LOW = MID+1


        print(Res, end = ' ')
        print(Res_possibleAns)




if __name__ == "__main__":
    main()