from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))

import heapq

"""

sort based on time
blocks
we can find the max value

"""

def answer():

    d = dict()
    for i in range(n):
        if(a[i] not in d):
            d[a[i]] = []

        d[a[i]].append(t[i])


    keys = list(d.keys())
    keys.sort()


    ans = 0
    q , prev = [] , -1
    for x in keys:

        if(prev != -1):

            for i in range(x - prev):
                if(len(q) == 0):break
                v , start = heapq.heappop(q)
                v = -v

                ans += ((prev + i) - start) * v


        for i in d[x]:
            heapq.heappush(q , [-i , x])

        prev = x



    c = 0
    while(len(q)):
        v , start = heapq.heappop(q)
        v = -v

        ans += ((prev + c) - start) * v
        c += 1
  
    return ans
            
    
for T in range(1):

    n = int(input())
    a = inp()
    t = inp()


    print(answer())
    
