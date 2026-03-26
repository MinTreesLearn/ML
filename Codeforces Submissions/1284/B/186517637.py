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


arrays = []

genCnt = 0;

count = 0;


maxes, mins = [], []
for _ in range(n):
    array = list(map(int, input().split()))
    
    array = array[1:]
    
    if array != sorted(array, reverse = True):
        continue
    else:
        maxes.append(max(array));
        mins.append(min(array))
        



mins.sort()
maxes.sort()



def bisectLeft(val):
    leftPointer, rightPointer = 0, len(maxes) - 1
    
    ans = -1
    while(rightPointer >= leftPointer):
        middlePointer = (rightPointer + leftPointer) // 2
        if maxes[middlePointer] <= val:
            ans = middlePointer;
            leftPointer = middlePointer + 1
        else:
            rightPointer = middlePointer - 1
    
    return ans;            


for num in mins:
    count += bisectLeft(num) + 1

print((n * n) - count)    