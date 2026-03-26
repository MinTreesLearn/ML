# Thank God that I'm not you.
from itertools import permutations, combinations;
import heapq;
from collections import Counter, deque;
import math;
import sys;






m, mod = map(int, input().split())


array = list(map(int, input().split()));



for i, num in enumerate(array):
    array[i] = [(num % mod), num];


counter = Counter()


for numOne, numTwo in array:
    counter[numOne] += 1;


def solve():
    hashMap = {}
    for num in counter:
        if counter[num] > 1:
            return 0;


    for numOne, numTwo in array:
        hashMap[numOne] = numTwo;


    ans = 1;
    arr = sorted(list(counter.keys()));


    for i in range(len(arr)):
        for y in range(i + 1, len(arr)):
            ans *= ((abs(hashMap[arr[y]] - hashMap[arr[i]])) % mod);
            ans %= mod;
    return ans;


print(solve())