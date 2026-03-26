######################################################################################
#------------------------------------Template---------------------------------------#
######################################################################################
import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

def vsInput():
    sys.stdin = open('inputf.in', 'r')
    sys.stdout = open('outputf.out', 'w')


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
def input(): return sys.stdin.readline().rstrip("\r\n")


######################################################################################
#--------------------------------------Input-----------------------------------------#
######################################################################################

def value(): return tuple(map(int, input().split()))
def inlt(): return [int(i) for i in input().split()]
def inp(): return int(input())
def insr(): return input()
def stlt(): return [i for i in input().split()]


######################################################################################
#------------------------------------Functions---------------------------------------#
######################################################################################


def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    l = []
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n+1):
        if prime[p]:
            l.append(p)
            # print(p)
        else:
            continue
    return l


def isPrime(n):
    prime_flag = 0

    if n > 1:
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                prime_flag = 1
                break
        if prime_flag == 0:
            return True
        else:
            return False
    else:
        return False


def gcdofarray(a):
    x = 0
    for p in a:
        x = math.gcd(x, p)
    return x


def printDivisors(n):
    i = 1
    ans = []
    while i <= math.sqrt(n):
        if (n % i == 0):
            if (n / i == i):
                ans.append(i)
            else:
                ans.append(i)
                ans.append(n // i)
        i = i + 1
    ans.sort()
    return ans


def binaryToDecimal(n):
    return int(n, 2)


def countTriplets(a, n):
    s = set()
    for i in range(n):
        s.add(a[i])
    count = 0
    for i in range(n):
        for j in range(i + 1, n, 1):
            xr = a[i] ^ a[j]
            if xr in s and xr != a[i] and xr != a[j]:
                count += 1
    return int(count // 3)


def countOdd(L, R):
    N = (R - L) // 2
    if (R % 2 != 0 or L % 2 != 0):
        N += 1
    return N


def isPalindrome(s):
    return s == s[::-1]


def sufsum(a):
    test_list = a.copy()
    test_list.reverse()
    n = len(test_list)
    for i in range(1, n):
        test_list[i] = test_list[i] + test_list[i - 1]
    return test_list


def prsum(b):
    a = b.copy()
    for i in range(1, len(a)):
        a[i] += a[i - 1]
    return a


def badachotabadachota(nums):
    nums.sort()
    i = 0
    j = len(nums) - 1
    ans = []
    cc = 0
    while len(ans) != len(nums):
        if cc % 2 == 0:
            ans.append(nums[j])
            j -= 1
        else:
            ans.append(nums[i])
            i += 1
        cc += 1
    return ans


def chotabadachotabada(nums):
    nums.sort()
    i = 0
    j = len(nums) - 1
    ans = []
    cc = 0
    while len(ans) != len(nums):
        if cc % 2 == 1:
            ans.append(nums[j])
            j -= 1
        else:
            ans.append(nums[i])
            i += 1
        cc += 1
    return ans


def primeFactors(n):
    ans = []
    while n % 2 == 0:
        ans.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            ans.append(i)
            n = n // i
    if n > 2:
        ans.append(n)
    return ans


def closestMultiple(n, x):
    if x > n:
        return x
    z = (int)(x / 2)
    n = n + z
    n = n - (n % x)
    return n


def getPairsCount(arr, n, sum):
    m = [0] * 1000
    for i in range(0, n):
        m[arr[i]] += 1
    twice_count = 0
    for i in range(0, n):
        twice_count += m[int(sum - arr[i])]
        if (int(sum - arr[i]) == arr[i]):
            twice_count -= 1
    return int(twice_count / 2)


def remove_consec_duplicates(test_list):
    res = [i[0] for i in itertools.groupby(test_list)]
    return res


def BigPower(a, b, mod):
    if b == 0:
        return 1
    ans = BigPower(a, b//2, mod)
    ans *= ans
    ans %= mod
    if b % 2:
        ans *= a
    return ans % mod


def nextPowerOf2(n):
    count = 0
    if (n and not(n & (n - 1))):
        return n
    while(n != 0):
        n >>= 1
        count += 1
    return 1 << count


# This function multiplies x with the number
# represented by res[]. res_size is size of res[]
# or number of digits in the number represented
# by res[]. This function uses simple school
# mathematics for multiplication. This function
# may value of res_size and returns the new value
# of res_size
def multiply(x, res, res_size):

    carry = 0  # Initialize carry

    # One by one multiply n with individual
    # digits of res[]
    i = 0
    while i < res_size:
        prod = res[i] * x + carry
        res[i] = prod % 10  # Store last digit of
        # 'prod' in res[]
        # make sure floor division is used
        carry = prod//10  # Put rest in carry
        i = i + 1

    # Put carry in res and increase result size
    while (carry):
        res[res_size] = carry % 10
        # make sure floor division is used
        # to avoid floating value
        carry = carry // 10
        res_size = res_size + 1

    return res_size


def Kadane(a, size):

    max_so_far = -1e18 - 1
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far


def highestPowerof2(n):
    res = 0
    for i in range(n, 0, -1):
        if ((i & (i - 1)) == 0):
            res = i
            break
    return res


def MEX(nList, start):
    nList = set(nList)
    mex = start
    while mex in nList:
        mex += 1
    return mex


def getClosest(val1, val2, target):

    if (target - val1 >= val2 - target):
        return val2
    else:
        return val1
    

def tobinary(a): return bin(a).replace('0b', '')


def nextPerfectSquare(N):

    nextN = math.floor(math.sqrt(N)) + 1

    return nextN * nextN


def modFact(n, p):
    result = 1
    for i in range(1, n + 1):
        result *= i
        result %= p
 
    return result

def maxsubarrayproduct(arr):
  
    n = len(arr)
    max_ending_here = 1
    min_ending_here = 1
    max_so_far = 0
    flag = 0

    for i in range(0, n):
  
        if arr[i] > 0:
            max_ending_here = max_ending_here * arr[i]
            min_ending_here = min (min_ending_here * arr[i], 1)
            flag = 1
  
        elif arr[i] == 0:
            max_ending_here = 1
            min_ending_here = 1
  
        else:
            temp = max_ending_here
            max_ending_here = max (min_ending_here * arr[i], 1)
            min_ending_here = temp * arr[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here
              
    if flag == 0 and max_so_far == 0:
        return 0
    return max_so_far


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p


def sqrtl(x):
    if (x == 0 or x == 1):
        return x
    start = 1
    end = x//2
    while (start <= end):
        mid = (start + end) // 2
        if (mid*mid == x):
            return mid
        if (mid * mid < x):
            start = mid + 1
            ans = mid
        else:
            end = mid-1
 
    return ans
 
 
def ceill(a, b):
    return (a // b) + int(a % b != 0)



def LcmOfArray(arr, idx):
   
    # lcm(a,b) = (a*b/gcd(a,b))
    if (idx == len(arr)-1):
        return arr[idx]
    a = arr[idx]
    b = LcmOfArray(arr, idx+1)
    return int(a*b/ math.gcd(a,b))
    
# #####################################################################################################
alphabets = list("abcdefghijklmnopqrstuvwxyz")
vowels = list("aeiou")
MOD1 = int(1e9 + 7)
MOD2 = 998244353    
INF = int(1e17)
# ########################################################################
# #-----------------------------Code Here--------------------------------#
########################################################################

# vsInput()   
for _ in range(inp()):
    n = inp()
    a = inlt()
    i = 0
    while i < n and a[i] >= i:
        i += 1
    buu = 1
    while i < n:
        if a[i - 1] <= a[i]:
            a[i] = a[i - 1] - 1
        if a[i] < 0:
            print("NO")
            buu = 0
            break
        i += 1
    if buu:
        print("YES")