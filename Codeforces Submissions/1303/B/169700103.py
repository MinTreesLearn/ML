from sys import stdin
input = stdin.readline

from math import ceil

inp = lambda : list(map(int,input().split()))

"""
we need n / 2 good days
"""

def answer():

    x = n // 2 + (n % 2)
    y = x // g
    good = y * g
    bad = (y - 1) * b

    if(x % g):
        good += x % g
        bad += b


    req = max(0 , n - (good + bad))
    return good + bad + req
        
  
for T in range(int(input())):

    n , g , b = inp()

    print(answer())

    
