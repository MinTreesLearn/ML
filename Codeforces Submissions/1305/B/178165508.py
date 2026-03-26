# UCSD fa22 Week 5

import sys
from collections import Counter, defaultdict
input = sys.stdin.readline
flush = sys.stdout.flush
iil = lambda: [int(x) for x in input().split()]
YES:str = "YES"
NO:str = "NO"

string: str = input()[:-1]
left, right = 0, len(string) - 1
dels:list[int] = []
dir = 0
while left < right:
    while left < len(string) and string[left] != "(":
        left += 1
    while right >= 0 and string[right] != ")":
        right -= 1
    if 0 <= left < right < len(string):
        dels.extend([left+1, right+1])
        left += 1
        right -= 1
if len(dels) != 0:
    print(1)
    print(len(dels))
    print(" ".join(map(str,sorted(dels))))
else:
    print(0)


	    			 	     			  	 			 	   	