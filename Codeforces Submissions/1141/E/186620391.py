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







h, n = map(int, input().split())


array = list(map(int, input().split()))



def solve():
    sumElems = sum(array)
    
    
    currHp = h;
    for i, num in enumerate(array):
        currHp += num;
        if currHp <= 0:
            return i + 1
    
    if sumElems >= 0:
        return -1;
    
    
    leftPointer, rightPointer = 0, 10**15 + 5;
    
    ans = None;
    
    def can(rnds):
        currHp = h;
        currHp += (rnds * sumElems)
        
        if currHp <= 0:
            return True;
        
        for num in array:
            currHp += num;
            if currHp <= 0:
                return True;
        
        return False;        
        
    
    while(rightPointer >= leftPointer):
        middlePointer = (leftPointer + rightPointer) // 2;
        
        if can(middlePointer):
            ans = middlePointer;
            rightPointer = middlePointer - 1;
        else:
            leftPointer = middlePointer + 1    
    
    newAn = ans * n;
    
    currHp = h;
    currHp += (ans * sumElems); 
    if currHp <= 0:
        return newAn;

    for num in array:
        currHp += num;    
        newAn += 1
        if currHp <= 0:
            return newAn;
   
    return -1

print(solve())