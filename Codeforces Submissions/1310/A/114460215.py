inf=float('inf')
from heapq import heapify,heappop,heappush
from collections import defaultdict
if __name__=='__main__':
   n=int(input())
   lst=list(map(int,input().split(' ')))
   tm=list(map(int,input().split(' ')))
   l=[]
   for i in range(n):
      l.append([lst[i],tm[i]])
   l.sort()
   l.append((10**12,0))
   cnt = 0
   prev=0
   now = []
   for x in l:
      a,t = x
      for ai in range(prev,a):
         if not now:
            break
         tm,am = heappop(now)
         tm = 10**5-tm
         cnt += (ai-am) * tm
      heappush(now,(10**5-t,a))
      prev=a
   print(cnt)