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

import math
n=int(input())
vals=list(map(int,input().split()))
#count the oddeven,oddodd and eveneven
complexity=0
for s in range(n):
    if vals[s]==0:
        vals[s]="x"
odds=math.ceil(n/2)
evens=n//2
for s in range(n):
    if vals[s]!="x":
        if vals[s]%2==0:
            evens-=1
        else:
            odds-=1
for s in range(1,n):
    if vals[s]!="x":
        if vals[s-1]!="x":
            if vals[s-1]%2!=vals[s]%2:
                complexity+=1
odd=[]
sodd=[]
even=[]
seven=[]
oddeven=[]
chain=0
start=(0,-1)
end=(0,0)
for s in range(n):
    if vals[s]=="x":
        chain+=1
    else:
        parity=vals[s]%2
        end=(parity,s)
        if chain>0:
            if start==(0,-1):
                if parity==0:
                    seven.append(chain)
                else:
                    sodd.append(chain)
            else:
                if start[0]==0 and end[0]==0:
                    even.append(chain)
                elif start[0]==1 and end[0]==1:
                    odd.append(chain)
                else:
                    oddeven.append(chain)
        chain=0
        start=(parity,s)
if vals[n-1]=="x":
        if chain>0:
            if start==(0,0):
                if n==1:
                    odd.append(chain)
                else:
                    oddeven.append(chain)
            else:
                if start[0]==0:
                    seven.append(chain)
                elif start[0]==1:
                    sodd.append(chain)
                else:
                    oddeven.append(chain)
        chain=0
odd.sort()
odd.reverse()
even.sort()
even.reverse()
oddeven.sort()
oddeven.reverse()
seven.sort()
seven.reverse()
sodd.sort()
sodd.reverse()
while odds>0 and (len(odd)>0 or len(sodd)>0):
    if len(odd)>0 and len(sodd)>0:
        if len(sodd)==2:
            if sum(sodd)<odd[-1]:
                odds-=sodd[-1]
                if odds>=0:
                    sodd.pop()
                    odds-=sodd[-1]
                    if odds>=0:
                        sodd.pop()
            else:
                if odds>=odd[-1]:
                    odds-=odd[-1]
                    odd.pop()
                else:
                    odds-=sodd[-1]
                    if odds>=0:
                        sodd.pop()
        elif len(sodd)==1:
            if odds>=odd[-1]:
                odds-=odd[-1]
                if odds>=0:
                    odd.pop()
            else:
                odds-=sodd[-1]
                if odds>=0:
                    sodd.pop()
    else:
        #one of them is 0
        if len(odd)>0:
            odds-=odd[-1]
            if odds>=0:
                odd.pop()
        else:
            odds-=sodd[-1]
            if odds>=0:
                sodd.pop()
#
while evens>0 and (len(even)>0 or len(seven)>0):
    if len(even)>0 and len(seven)>0:
        if len(seven)==2:
            if sum(seven)<even[-1]:
                evens-=seven[-1]
                if evens>=0:
                    seven.pop()
                    evens-=seven[-1]
                    if evens>=0:
                        seven.pop()
            else:
                if evens>=even[-1]:
                    evens-=even[-1]
                    even.pop()
                else:
                    evens-=seven[-1]
                    if evens>=0:
                        seven.pop()
        elif len(seven)==1:
            if evens>=even[-1]:
                evens-=even[-1]
                if evens>=0:
                    even.pop()
            else:
                evens-=seven[-1]
                if evens>=0:
                    seven.pop()
    else:
        #one of them is 0
        if len(even)>0:
            evens-=even[-1]
            if evens>=0:
                even.pop()
        else:
            evens-=seven[-1]
            if evens>=0:
                seven.pop()
complexity+=len(odd)*2+len(even)*2+len(sodd)+len(seven)+len(oddeven)
if n==1:
    print(0)
else:
    print(complexity)
#i forgot to count initial complexity