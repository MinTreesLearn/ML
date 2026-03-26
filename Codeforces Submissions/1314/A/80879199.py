import heapq
from sys import stdin,stdout
from collections import defaultdict
def main():
    n=int(stdin.readline())
    a=[int(k) for k in stdin.readline().split()]
    t=[int(k) for k in stdin.readline().split()]
    dic=defaultdict(list)
    cat=[]
    for i in range(n):
        dic[a[i]].append(t[i])
    used=set()
    l=set(a)
    lis=list(l)
    heapq.heapify(lis)
    res=0
    sm=0
    while lis:
        curr=heapq.heappop(lis)
        if curr in used:
            continue
        used.add(curr)
        for el in dic[curr]:
            sm+=el
            heapq.heappush(cat,-el)
        if cat:
            el=-heapq.heappop(cat)
            sm-=el
            res+=sm
            heapq.heappush(lis,curr+1)
    
    print(res)
main()