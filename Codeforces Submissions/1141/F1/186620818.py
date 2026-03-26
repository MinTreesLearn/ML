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


hashMap = {}


for i in range(n):
    currentSum = 0
    for x in range(i, n):
        currentSum += array[x]
        left, right = i, x;
        if currentSum not in hashMap:
            hashMap[currentSum] = [[[left, right], 1]]
        else:
            currentMax = 0
            for (leftOne, rightOne), cnt in hashMap[currentSum]:
                if (rightOne) < left:
                    currentMax = max(currentMax, cnt)
            
            hashMap[currentSum].append([[left, right], currentMax + 1])

currentMax, sumAss = 1, None;
for sumElems in hashMap:
    for _, cnt in hashMap[sumElems]:
        if cnt >= currentMax:
            currentMax = cnt;
            sumAss = sumElems;

lastSegment = None;

result = []
for segment, cnt in hashMap[sumAss][::-1]:
    if not currentMax:
        break;
    if cnt == currentMax:
        if lastSegment is None:
            lastSegment = segment;
            result.append(segment);
            currentMax -= 1
            continue
        leftOne, rightOne = lastSegment
        leftTwo, rightTwo = segment
        if leftOne > rightTwo:
            lastSegment = segment
            result.append(segment)
            currentMax -= 1
      

print(len(result))

for left, right in result:
    print(left + 1, right + 1)         
            
        
                
                
                                  