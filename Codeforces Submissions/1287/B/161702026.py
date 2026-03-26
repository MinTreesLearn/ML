#Don't stalk me, don't stop me, from making submissions at high speed. If you don't trust me,
import sys
#then trust me, don't waste your time not trusting me. I don't plagiarise, don't fantasize,
import os
#just let my hard work synthesize my rating. Don't be sad, just try again, everyone fails
from io import BytesIO, IOBase
BUFSIZE = 8192
#every now and then. Just keep coding, just keep working and you'll keep progressing at speed-
# -forcing.
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
#code by _Frust(CF)/Frust(AtCoder)
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def hasher(str1, prime=257, mod=1000000007):
    po=1
    p1=prime
    h=0
    for i in range(len(str1)):
        h=(h + (po * (ord(str1[i]) - ord("a") + 1))%mod)%mod
        po=(po * p1)%mod
    return h
    


# n=int(input())
n, k=map(int, input().split())
l1=[]
d1={}
for i in range(n):
    s1=input()
    l1.append(s1)
    hc1=hasher(s1, 257)
    hc2=hasher(s1, 263)
    d1[(hc1, hc2)]=d1.get((hc1, hc2), 0)+1
    
ans=0
for i in range(n):
    for j in range(i+1, n):
        h1, p1, po1=0, 257, 1
        h2, p2, po2=0, 263, 1
        mod=1000000007
        for l in range(k):
            req=""
            if l1[i][l]==l1[j][l]:
                req=l1[i][l]
                
            else:
                for letter in "SET":
                    if l1[i][l]!=letter and l1[j][l]!=letter:
                        req=letter
                        break
                    
            h1=(h1 + (po1 * (ord(req) - ord("a") + 1))%mod)%mod
            po1=(po1*p1)%mod
            
            h2=(h2 + (po2 * (ord(req) - ord("a") + 1))%mod)%mod
            po2=(po2*p2)%mod
        ans+=d1.get((h1, h2), 0)
print(ans//3)