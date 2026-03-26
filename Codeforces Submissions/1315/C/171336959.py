#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase


def main():
    for _ in range(int(input())):
        n=int(input())
        b=[int(x) for x in input().split()]
        L=[]
        B=[]
        X=[0]*n
        H=[0]*(2*n)
        a=[0]*(2*n)
        v=b.copy()
        for i in range(n):
            a[(2*i)]=b[i]


        for i in range(1,(2*n)+1):
            if i not in b:
                L.append(i)


        L.sort()


        for i in range(n):
            B.append([b[i],i])

        B.sort()
    

        for i in range(n):
            B[i]=[B[i][0],L[i],B[i][1]]

        # print('B=',B)
        c=0

        for i in range(n):
            # print(B[i][2],'indx')
    
            H[2*B[i][2]]=B[i][0]
            H[2*B[i][2]+1]=B[i][1]
         

        for i in range(n-1):
            for j in range(i+1,n):
                if H[(2*j)+1]<H[(2*i)+1]:
                    if H[(2*j)]<H[(2*i)+1] and H[2*i]<H[(2*j)+1]:
                        H[(2*j)+1],H[(2*i)+1]=H[(2*i)+1],H[(2*j)+1]


            
        



        for i in range(n):
            X[i]=min(H[2*i],H[(2*i)+1])

        if X!=b:
            print(-1)

        else:
            for i in H:
                print(i,end=" ")
            print()


   
   

    
     

       

  
  

    


    

    

    #code



# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._file = file
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

# endregion

if __name__ == "__main__":
    main()























