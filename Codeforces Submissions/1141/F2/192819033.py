import io, os, sys, atexit
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
inputs =lambda: input().decode().strip()
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode())
atexit.register(lambda: os.write(1, stdout.getvalue()))


## code start
from collections import defaultdict
from itertools import accumulate
n=int(input())
a=[*map(int,input().split())]
presum=list(accumulate(a,initial=0))  # 前缀和

data=defaultdict(list) 
for h in range(n):
    for t in range(h+1,n+1):
        data[presum[t]-presum[h]].append((h+1,t))   # 以区间和为键值, 建立字典, 记录所有区间和为该键值的起终点

maxcnt,res=0,[]
for key in data:                   # 枚举区间和
    data[key].sort(key=lambda x:x[1])    # 所有区间按终点排序
    cnt,prev=0,-1                 
    for a,b in data[key]:
        if a>prev:              # 如果起点大于上一段终点, 贪心加入
            cnt+=1            # 计数加1
            prev=b            # 终点变成本区间终点
    if cnt>maxcnt:
        maxcnt=cnt
        res=key
        
        
print(maxcnt)
prev=-1
for a,b in data[res]:
    if a>prev:
        print(a,b)
        prev=b

    
