
class RMQMIN(): #for MIN queries
    def __init__(self,arr):
        self.arr=arr
        MAXN=len(arr)
        # build log table for fast lookup
        self.log2=[0]*(MAXN+1)
        i=0
        while 2**i<(MAXN+1):
            self.log2[2**i]=i;i+=1
        for i in range(1,MAXN+1):
            if self.log2[i]==0:self.log2[i]=self.log2[i-1]
        K=self.log2[MAXN]+1
        # self.lookup=[[0 for _ in range(K+1)] for __ in range(MAXN)]
        self.lookup=[0] * ((K + 1) * MAXN)
        self.M = K + 1 # number of columns in self.lookup. To do calculations for self.lookup when converted from 2D to 1D
        self.buildSparseTable()
    def buildSparseTable(self): 
        n=len(self.arr) 
        for i in range(0,n):  
            self.lookup[i*self.M] = self.arr[i]  
        j=1
        while (1<<j)<=n:
            i=0
            while (i+(1<<j)-1)<n:
                self.lookup[i*self.M+j]=min(self.lookup[i*self.M+j-1],self.lookup[(i+(1<<(j-1)))*self.M+j-1])
                i += 1
            j += 1
    def query(self,L,R): #returns min on interval [l,r] inclusive
        j = self.log2[R-L+1]
        return min(self.lookup[L*self.M+j],self.lookup[(R-(1<<j)+1)*self.M+j])

class RMQMAX(): #for MAX queries
    def __init__(self,arr):
        self.arr=arr
        MAXN=len(arr)
        # build log table for fast lookup
        self.log2=[0]*(MAXN+1)
        i=0
        while 2**i<(MAXN+1):
            self.log2[2**i]=i;i+=1
        for i in range(1,MAXN+1):
            if self.log2[i]==0:self.log2[i]=self.log2[i-1]
        K=self.log2[MAXN]+1
        # self.lookup=[[0 for _ in range(K+1)] for __ in range(MAXN)]
        self.lookup=[0] * ((K + 1) * MAXN)
        self.M = K + 1 # number of columns in self.lookup. To do calculations for self.lookup when converted from 2D to 1D
        self.buildSparseTable()
    def buildSparseTable(self): 
        n=len(self.arr)
        for i in range(0,n):  
            self.lookup[i*self.M] = self.arr[i]  
        j=1
        while (1<<j)<=n:
            i=0
            while (i+(1<<j)-1)<n:
                self.lookup[i*self.M+j]=max(self.lookup[i*self.M+j-1],self.lookup[(i+(1<<(j-1)))*self.M+j-1])
                i += 1
            j += 1
    def query(self,L,R): #returns min on interval [l,r] inclusive
        j = self.log2[R-L+1]
        return max(self.lookup[L*self.M+j],self.lookup[(R-(1<<j)+1)*self.M+j])

def check(arr):
    ''' Check all pairwise overlaps in a are overlaps in b '''
    n = len(arr)
    arr.sort(key=lambda x: x[0])  # sort by la asc
    min_rb_arr = []
    max_lb_arr = []
    for i in range(n):
        la, ra, lb, rb = arr[i]
        min_rb_arr.append(rb)
        max_lb_arr.append(lb)
    rb_min = RMQMIN(min_rb_arr)
    lb_max = RMQMAX(max_lb_arr)

    for i in range(n):
        lo, hi = -1, n - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if arr[mid][0] <= arr[i][1]:
                lo = mid
            else:
                hi = mid - 1
        max_idx = lo
        if max_idx == i:
            continue
        if rb_min.query(i + 1, max_idx) < arr[i][2]:
            return False
        if lb_max.query(i + 1, max_idx) > arr[i][3]:
            return False
    return True

def main():
    
    n = int(input())
    arr1 = []
    arr2 = []
    for _ in range(n):
        la, ra, lb, rb = readIntArr()
        arr1.append((la, ra, lb, rb))
        arr2.append((lb, rb, la, ra))
    
    is_happy = check(arr1) and check(arr2)
    ans = 'YES' if is_happy else 'NO'
    print(ans)
    
    

    return

import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(a, b):
    print('? {} {}'.format(a, b))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353
 
from math import gcd,floor,ceil
import math
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()