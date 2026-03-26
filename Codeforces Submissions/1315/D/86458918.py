# ------------------- fast io --------------------
import os
import sys
from io import BytesIO, IOBase
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# ------------------- fast io --------------------

import heapq
n=int(input())
nums=list(map(int,input().split()))
cost=list(map(int,input().split()))
#gonna have to use a max heap here
dict1={}
for s in range(n):
    if not(nums[s] in dict1):
        dict1[nums[s]]=[cost[s]]
    else:
        dict1[nums[s]].append(cost[s])
nums=set(nums)
nums=list(nums)
nums.sort()
heapy=[]
heapq.heapify(heapy)
summy=0
ans=0
for s in range(len(nums)):
    #i need another check here
    if len(heapy)>0:
        #this is negative
        ans+=summy
    while len(dict1[nums[s]])>0:
        v0=(dict1[nums[s]].pop())
        heapq.heappush(heapy,-v0)
        summy+=v0
    v1=heapq.heappop(heapy)
    dict1[nums[s]].append(-v1)
    summy-=-v1
    if s<len(nums)-1:
        for b in range(min(nums[s+1]-1-nums[s],len(heapy))):
            ans+=summy
            v2=heapq.heappop(heapy)
            summy-=-v2
    else:
        for b in range(len(heapy)):
            ans+=summy
            v2=heapq.heappop(heapy)
            summy-=-v2
print(ans)