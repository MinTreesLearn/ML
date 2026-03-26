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


stringOne, stringTwo = input().rstrip(), input().rstrip()


hashMap = {char: [] for char in "abcdefghijklmnopqrstuvwxyz"}


for i, char in enumerate(stringTwo):
    if char == "?":
        continue
    
    hashMap[char].append(i)



result = []

pairedOne, pairedTwo = set(), set();
for i, char in enumerate(stringOne):
    if char in hashMap and hashMap[char]:
        idx = hashMap[char].pop()
        result.append([i + 1, idx + 1])
        pairedOne.add(i)
        pairedTwo.add(idx)


unPaired = []
for i, char in enumerate(stringTwo):
    if char != "?" and i not in pairedTwo:
        unPaired.append(i)


marksOne = []
for i, char in enumerate(stringOne):
    if char == "?":
        if unPaired:
            result.append([i + 1, unPaired.pop() + 1])
        else:
            marksOne.append(i)


marksTwo = [];
for i, char in enumerate(stringTwo):
    if char == "?":
        if marksOne:
            result.append([marksOne.pop() + 1, i + 1])
        else:
            marksTwo.append(i)    


for i, char in enumerate(stringOne):
    if char != "?" and i not in pairedOne:
        if marksTwo:
            result.append([i + 1, marksTwo.pop() + 1])

print(len(result))

for res in result:
    print(*res)            
            
                    
                           
        
            

