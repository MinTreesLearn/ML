import math
import sys
import bisect
# sys.stdin = open('input.txt', 'r') 
# sys.stdout = open('output.txt', 'w')

Mod = 1000000007
# t = int(input())
t=1
while t>0:
  t-=1
  #n = q(m+1) + r 
  n = int(input())
  a = list(map(int, input().split(' ')))
  b = list(map(int, input().split(' ')))
  a1 = [0]*n
  a2 = [0]*n
  for i in range(n):
    a1[i] = a[i]-b[i]
    a2[i] = -a[i]+b[i]
  ans = 0
  for i in range(n):
    if(a1[i]>a2[i]):
      ans-=1
  a2.sort()
  for x in a1:

     ans+=bisect.bisect_left(a2,x)
     #find index of first elem eql or greater than x
  print(ans//2)







  



  