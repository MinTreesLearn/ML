import sys
import math
from math import *
import builtins

input = sys.stdin.readline


def print(x, end='\n'):
    sys.stdout.write(str(x) + end)


# IO helpers
def get_int():
    return int(input())


def get_list_ints():
    return list(map(int, input().split()))


def get_char_list():
    s = input()
    return list(s[:len(s) - 1])


def get_tuple_ints():
    return tuple(map(int, input().split()))


def print_iterable(p):
    print(" ".join(map(str, p)))


def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return high
def find_gcd(x, y):
     
    while(y):
        x, y = y, x % y
     
    return x
# Python3 program to calculate
# Euler's Totient Function
def phi(n):
     
    # Initialize result as n
    result = n;
 
    # Consider all prime factors
    # of n and subtract their
    # multiples from result
    p = 2;
    while(p * p <= n):
         
        # Check if p is a
        # prime factor.
        if (n % p == 0):
             
            # If yes, then
            # update n and result
            while (n % p == 0):
                n = int(n / p);
            result -= int(result / p);
        p += 1;
 
    # If n has a prime factor
    # greater than sqrt(n)
    # (There can be at-most
    # one such prime factor)
    if (n > 1):
        result -= int(result / n);
    return result;


def main():
    n=get_int()
    for i in range(n):
        [a,m]=get_list_ints()
        g=find_gcd(a,m)
        p2=m//g
        ans=phi(p2)
        print(ans)
    pass

if __name__ == '__main__':
    main()
  	 						  		    				 			  			