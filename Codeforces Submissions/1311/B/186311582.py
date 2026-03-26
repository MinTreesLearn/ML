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






t = int(input())


result = []
for _ in range(t):
    n, m = map(int, input().split())
    
    
    array = list(map(int, input().split()))
    
    positions = list(map(int, input().split()))
    
    
    
    def solve():
        
        
        positions.sort()
        
        
        def swap(idxOne, idxTwo):
            array[idxOne], array[idxTwo] = array[idxTwo], array[idxOne];
        
        
        
        while(array != sorted(array)):
            state = False;
        
            for pos in positions:
                pos -= 1
                firstNum, secondNum = array[pos], array[pos + 1]
                
                if firstNum > secondNum:
                    state = True;
                    swap(pos, pos + 1)
            
            if not state:
                break;        
        
        if array == sorted(array):
            return "YES"        
        
        return "NO"
    
    print(solve())

# print(result)        