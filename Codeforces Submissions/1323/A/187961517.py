from sys import stdin	
from typing import List


def readarray(typ):
    return list(map(typ, stdin.readline().split()))


def solveDP(arr: List[int], left: int, right: int, currentSum: int, indices: List[int], dp: dict):


    if currentSum != 0 and currentSum % 2 == 0:
        return [indices, currentSum]

    if left > right:
        return []
    
    key = currentSum

    if key in dp:
        return dp[key]

    f1 = solveDP(arr, left+1, right, currentSum + arr[left], indices + [left+1], dp)
    f2 = solveDP(arr, left+1, right, currentSum, indices, dp)

    if not f1 and f2:
        dp[key] = f2
    elif f1 and not f2:
        dp[key] = f1
    elif not f1 and not f2:
        dp[key] = f1 
    else:
        dp[key] = f1 if len(f1[0]) <= len(f2[0]) else f2

    return dp[key]

    
for _ in range(int(input())):

    n = int(input())
    arr = readarray(int)

    if n == 1:
        if arr[0] % 2 == 0:
            print(1)
            print(1)
        else:
            print(-1)
    else:
        res = solveDP(arr, 0, n-1, 0, [], {})[0]
        print(len(res))
        print(*res)
                
