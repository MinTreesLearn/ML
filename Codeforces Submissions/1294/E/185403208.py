# Thank God that I'm not you.

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

input = sys.stdin.readline;
m = (10**9 + 7)
def mod_inv(n,m):
    n=n%m
    return pow(n,m-2,m)

def nCr(n,r,m):
    numerator=1
    for i in range(r):
        numerator=(numerator*(n-i))%m
    denomenator=1
    for i in range(2,r+1):
        denomenator=(denomenator*i)%m
    return (numerator*mod_inv(denomenator,m))%m



n, m = map(int, input().split())

matrix = [];
for i in range(n):
    matrix.append(list(map(int, input().split())));


identityMatrix = [];

num = 1;
for i in range(n):
    col = [];
    for j in range(m):
        col.append(num)
        num += 1;
    
    identityMatrix.append(col);    



count = 0;
def solve(colOne, colTwo):
    position = {}
    
    for i, num in enumerate(colTwo):
        position[num] = i;
    
    counter = Counter()
    
    currentMin = float('inf')
    
    for i, num in enumerate(colOne):
        if num not in position:
            continue
        pos = position[num]
        currDif = None
        if i >= pos:
            currDiff = i - pos;
        else:
            newPos = len(colOne) - 1  
            currDiff = (i + 1) + (newPos - pos)
        
        counter[currDiff] += 1; 
    
    for diff in counter:
        currentMin = min(currentMin, diff + (len(colOne) - counter[diff]))
    
    return min(currentMin, len(colOne))

count = 0
for col in range(m):
    colOne, colTwo = [], []
    for row in range(n):
        colOne.append(matrix[row][col])
        colTwo.append(identityMatrix[row][col])
    
    count += solve(colOne, colTwo)  
    
print(count)
        
                
                
    
    
        
    
    
