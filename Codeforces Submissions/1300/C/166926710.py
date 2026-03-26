import sys
import math
from os import path
from collections import defaultdict, Counter, deque
from bisect import *
from string import ascii_lowercase
import heapq
 
 
def readInts():
    x = list(map(int, (sys.stdin.readline().rstrip().split())))
    return x[0] if len(x) == 1 else x
 
 
def readList(type=int):
    x = sys.stdin.readline()
    x = list(map(type, x.rstrip('\n\r').split()))
    return x
 
 
def readStr():
    x = sys.stdin.readline().rstrip('\r\n')
    return x
 
 
write = sys.stdout.write
read = sys.stdin.readline
 
 
MAXN = 1123456
 
 
def dist(x1, x2, y1, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
 
 
def mergeSort(arr, check = lambda a, b: a < b, reverse = False):
    if len(arr) > 1:
  
        # Finding the mid of the array
        mid = len(arr)//2
  
        # Dividing the array elements
        L = arr[:mid]
  
        # into 2 halves
        R = arr[mid:]
  
        # Sorting the first half
        mergeSort(L, check, reverse)
  
        # Sorting the second half
        mergeSort(R, check, reverse)
  
        i = j = k = 0
  
        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if check(L[i], R[j]):
                if not reverse:
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
            else:
                if not reverse:
                    arr[k] = R[j]
                    j += 1
                else:
                    arr[k] = L[i]
                    i += 1 
            k += 1
  
        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
      
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
 
 
def kadanes(arr, k):
    
    max_sum = 0 
    max_cur = 0 
    for i, num in enumerate(arr):
        max_cur = max(max_cur + num, num)
        if max_cur > max_sum:
            max_sum = max_cur
            
    return max_sum
 
 
def lcm(a, b):
    return a*b//(math.gcd(a,b))
 
 
def get_power(n, m):
    i = 1
    p = -1
    while i <= n:
        i = i*m
        p += 1
    return p
 
 
def fact(n):
    f = 1
    for i in range(2, n+1):
        f *= i
    return f
 
 
def find_closest(num, ar):
    min_d = float('inf')
    for num2 in ar:
        d = abs(num2-num)
        if d < min_d:
            min_d = d
    return min_d 
 
 
def check_pal(n):
    s = str(n)
    j = len(s)-1
    i = 0
    while j > i:
        if s[i] != s[j]:
            return False
        i += 1
        j -= 1
 
    return True
 
 
def get_primes():
    primes = [False for _ in range(MAXN+1)]
    used = [False for _ in range(MAXN+1)]
    for i in range(2, MAXN+1):
        if not used[i]:
            primes[i] = True
            for j in range(i, MAXN+1, i):
                used[j] = True
    return primes
 
 
def isPrime(primes, n):
    if primes[n]:
        return True
 
    return False


def bit_not(n):
    if n == 0:
        return 1
    numbits = math.floor(math.log(n)/math.log(2))+1
    return (1 << numbits) - 1 - n


def solve(t, primes = None):
    n = readInts()
    ar = readList()
    # for num in ar:
    #     print(bit_not(num))
    pf = []
    p = (~ar[0])
    for num in ar:
        p = p&(~num)
        pf.append(p)
    
    sf = []
    s = (~ar[n-1])
    for i in range(n-1, -1, -1):
        s = s&(~ar[i])
        sf.append(s)

    tmp = float('-inf')
    ans = ar[0]
    # print(ar)
    # print(pf)
    # print(sf)
    for i in range(n):
        res = ar[i]

        if i > 0:
            res = res&pf[i-1]

        if i < n-1:
            res = res&sf[n-i-2]

        if res > tmp:
            ans = ar[i]
            tmp = res
        
        # print(ar[i], res)
        # print(ans)

    flag = False
    ansr = [ans]
    for num in ar:
        if num == ans:
            if flag:
                ansr.append(num)
            else:
                flag = True
        else:
            ansr.append(num)
    print(*ansr)
    

def main():
    t = 1
    if path.exists("F:/Comp Programming/input.txt"):
        sys.stdin = open("F:/Comp Programming/input.txt", 'r')
        sys.stdout = open("F:/Comp Programming/output.txt", 'w')
    # sys.setrecursionlimit(150000)
    # primes = get_primes()
    # t = readInts()
    for i in range(t):  
        solve(i+1)
 
 
if __name__ == '__main__':
    main()