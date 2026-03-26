import math
from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

n, m = map(int,input().split())

arr = list(map(int,input().split()))

if n > m:

  print(0)

else:

  prod = 1

  for i in range(0,n):


    for j in range(i+1,n):

      prod =  (prod *abs(arr[j]-arr[i])) % m

  print(prod % m)


# print answer modulo m