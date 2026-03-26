# Thank God that I'm not you.

import bisect
from collections import Counter, deque
import heapq
import itertools
import math
import random
import sys
from types import GeneratorType;

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc 

def primeFactors(n):
    
    counter = Counter(); 
    while n % 2 == 0:
        counter[2] += 1;
        n = n / 2
         
    
    for i in range(3,int(math.sqrt(n))+1,2):
         
        while n % i== 0:
            counter[i] += 1;
            n = n / i
             
    if (n > 2):
        counter[n] += 1;
    
    return counter;






n = int(input())


array = list(map(int, input().split()))


leftPointer = 1
rightPointer = n

ans = None

def can(middlePointer):
    arr = [middlePointer]

    lastNum = middlePointer
    visited = set({lastNum})
    for num in array[::-1]:
        newNum = lastNum - num;
        if newNum <= 0:
            return 0
        if newNum in visited or newNum > n:
            return 1
        arr.append(newNum)
        lastNum = newNum
        visited.add(newNum)
    
    return 2    
        

while(rightPointer >= leftPointer):
    middlePointer = (leftPointer + rightPointer) // 2
    
    state = can(middlePointer)
    
    if state == 0:
        leftPointer = middlePointer + 1
    elif state == 1:
        rightPointer = middlePointer - 1
    else:
        ans = middlePointer;
        break        
    


if ans is None:
    print(-1)
else:
    arr = [ans]    

    lastNum = ans;
    for num in array[::-1]:
        lastNum -= num
        arr.append(lastNum)
    
    print(*arr[::-1])    