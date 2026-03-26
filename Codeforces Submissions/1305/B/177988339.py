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
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


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
            n = n / i
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


def lower_bound(numbers, length, searchnum):
    answer = -1
    start = 0
    end = length - 1

    while start <= end:
        middle = (start + end)//2
        if numbers[middle] == searchnum:
            answer = middle
            end = middle - 1
        elif numbers[middle] > searchnum:
            end = middle - 1
        else:
            start = middle + 1
    return answer


def MEX(nList, start):
    nList = set(nList)
    mex = start
    while mex in nList:
        mex += 1
    return mex


def MinValue(N, X):
    N = list(N)
    ln = len(N)
    position = ln + 1
    # # If the given string N represent
    # # a negative value
    # if (N[0] == '-'):

    #     # X must be place at the last
    #     # index where is greater than N[i]
    #     for i in range(ln - 1, 0, -1):
    #         if ((ord(N[i]) - ord('0')) < X):
    #             position = i

    # else:
    #     # For positive numbers, X must be
    #     # placed at the last index where
    #     # it is smaller than N[i]
    for i in range(ln - 1, -1, -1):
        if ((ord(N[i]) - ord('0')) > X):
            position = i

    # Insert X at that position
    c = chr(X + ord('0'))

    str = N.insert(position, c)

    # Return the string
    return ''.join(N)


def findClosest(arr, n, target):
    if (target <= arr[0]):
        return arr[0]
    if (target >= arr[n - 1]):
        return arr[n - 1]
    i = 0
    j = n
    mid = 0
    while (i < j):
        mid = (i + j) // 2
        if (arr[mid] == target):
            return arr[mid]
        if (target < arr[mid]):
            if (mid > 0 and target > arr[mid - 1]):
                return getClosest(arr[mid - 1], arr[mid], target)
            j = mid
        else:
            if (mid < n - 1 and target < arr[mid + 1]):
                return getClosest(arr[mid], arr[mid + 1], target)
            i = mid + 1
    return arr[mid]


def getClosest(val1, val2, target):

    if (target - val1 >= val2 - target):
        return val2
    else:
        return val1


def ncr(n, r, p):

    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p
# #####################################################################################################
# #------------------------------------------GRAPHS---------------------------------------------------#
# #####################################################################################################


class Graph:
    def __init__(self, edges, n):
        self.adjList = [[] for _ in range(n)]
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.adjList[dest].append(src)


def BFS(graph, v, discovered):
    q = collections.deque()
    discovered[v] = True
    q.append(v)
    ans = []
    while q:
        v = q.popleft()
        ans.append(v)
        # print(v, end=' ')
        for u in graph.adjList[v]:
            if not discovered[u]:
                discovered[u] = True
                q.append(u)
        return ans
#############################################################################################################
#--------------------------------------------Fenwick Tree---------------------------------------------------#
#############################################################################################################


def getsumFT(BITTree, i):
    s = 0  # initialize result

    # index in BITree[] is 1 more than the index in arr[]
    i = i+1

    # Traverse ancestors of BITree[index]
    while i > 0:

        # Add current element of BITree to sum
        s += BITTree[i]

        # Move index to parent node in getSum View
        i -= i & (-i)
    return s

# Updates a node in Binary Index Tree (BITree) at given index
# in BITree. The given value 'val' is added to BITree[i] and
# all of its ancestors in tree.


def updatebit(BITTree, n, i, v):

    # index in BITree[] is 1 more than the index in arr[]
    i += 1

    # Traverse all ancestors and add 'val'
    while i <= n:

        # Add 'val' to current node of BI Tree
        BITTree[i] += v

        # Update index to that of parent in update View
        i += i & (-i)


# Constructs and returns a Binary Indexed Tree for given
# array of size n.
def construct(arr, n):

    # Create and initialize BITree[] as 0
    BITTree = [0]*(n+1)

    # Store the actual values in BITree[] using update()
    for i in range(n):
        updatebit(BITTree, n, i, arr[i])

    # Uncomment below lines to see contents of BITree[]
    # for i in range(1,n+1):
    #     print BITTree[i],
    return BITTree
#############################################################################################################
#--------------------------------------------Segment Tree---------------------------------------------------#
#############################################################################################################


def getMid(s, e):
    return s + (e - s) // 2


""" A recursive function to get the sum of values
    in the given range of the array. The following
    are parameters for this function.
 
    st --> Pointer to segment tree
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at index 0
    ss & se --> Starting and ending indexes of the segment
                represented by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range """


def getSumUtil(st, ss, se, qs, qe, si):

    # If segment of this node is a part of given range,
    # then return the sum of the segment
    if (qs <= ss and qe >= se):
        return st[si]

    # If segment of this node is
    # outside the given range
    if (se < qs or ss > qe):
        return 0

    # If a part of this segment overlaps
    # with the given range
    mid = getMid(ss, se)

    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2)


def updateValueUtil(st, ss, se, i, diff, si):

    # Base Case: If the input index lies
    # outside the range of this segment
    if (i < ss or i > se):
        return

    # If the input index is in range of this node,
    # then update the value of the node and its children
    st[si] = st[si] + diff

    if (se != ss):

        mid = getMid(ss, se)
        updateValueUtil(st, ss, mid, i,
                        diff, 2 * si + 1)
        updateValueUtil(st, mid + 1, se, i,
                        diff, 2 * si + 2)

# The function to update a value in input array
# and segment tree. It uses updateValueUtil()
# to update the value in segment tree


def updateValue(arr, st, n, i, new_val):

    # Check for erroneous input index
    if (i < 0 or i > n - 1):

        print("Invalid Input", end="")
        return

    # Get the difference between
    # new value and old value
    diff = new_val - arr[i]

    # Update the value in array
    arr[i] = new_val

    # Update the values of nodes in segment tree
    updateValueUtil(st, 0, n - 1, i, diff, 0)

# Return sum of elements in range from
# index qs (query start) to qe (query end).
# It mainly uses getSumUtil()


def getSum(st, n, qs, qe):

    # Check for erroneous input values
    if (qs < 0 or qe > n - 1 or qs > qe):

        print("Invalid Input", end="")
        return -1

    return getSumUtil(st, 0, n - 1, qs, qe, 0)

# A recursive function that constructs
# Segment Tree for array[ss..se].
# si is index of current node in segment tree st


def constructSTUtil(arr, ss, se, st, si):

    # If there is one element in array,
    # store it in current node of
    # segment tree and return
    if (ss == se):

        st[si] = arr[ss]
        return arr[ss]

    # If there are more than one elements,
    # then recur for left and right subtrees
    # and store the sum of values in this node
    mid = getMid(ss, se)

    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) + \
        constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)

    return st[si]


""" Function to construct segment tree
from given array. This function allocates memory
for segment tree and calls constructSTUtil() to
fill the allocated memory """


def constructST(arr, n):

    # Allocate memory for the segment tree

    # Height of segment tree
    x = (int)(math.ceil(math.log2(n)))

    # Maximum size of segment tree
    max_size = 2 * (int)(2**x) - 1

    # Allocate memory
    st = [0] * max_size

    # Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0)

    # Return the constructed segment tree
    return st


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

# #####################################################################################################
alphabets = list("abcdefghijklmnopqrstuvwxyz")
vowels = list("aeiou")
MOD1 = int(1e9 + 7)
MOD2 = 998244353
INF = int(1e18)
# ########################################################################
# #-----------------------------Code Here--------------------------------#
# ########################################################################

def ch(s):
    if '(' in s and ')' in s:
        i1 = s.index('(')
        i2 = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ')':
                i2 = i
                break
        return i1 < i2
    return False

# vsInput()   

# for _ in range(inp()):
a = [i for i in insr()]
st = []
# for i in a:
#     if i == '(':
#         st.append(i)
#     else:
#         if st:
#             st.pop()
if st:
    print(0)
else:
    if a.count(')') == len(a):
        print(0)
    else:
        ans = []
        s = set()
        newa = a.copy()
        while a and ch(newa):
            temp = []
            n = len(a)
            st = []
            i = 0
            j = n - 1
            while i < j:
                if a[i] == '(' and a[j] == ')':
                    if i + 1 not in s:
                        temp.append(i + 1)
                        s.add(i + 1)
                    if j + 1 not in s:
                        s.add(j + 1)
                        temp.append(j + 1)
                    i += 1
                    j -= 1
                else:
                    if a[i] != '(' or i + 1 in s:
                        i += 1
                    if a[j] != ')' or j + 1 in s:
                        j -= 1
            
            newa = []
            for i in range(n):
                if i + 1 in s:
                    continue
                else:
                    newa.append(a[i])
            ans.append(sorted(temp))
        print(len(ans))
        for i in ans:
            print(len(i))
            print(*i)