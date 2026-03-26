# Python3 program to do range minimum
# query using sparse table
import math


# Fills lookup array lookup[][] in
# bottom up manner.
def buildSparseTable(arr, n):
    # Initialize M for the intervals
    # with length 1
    for i in range(0, n):
        lookup[i][0] = arr[i]

    j = 1

    # Compute values from smaller to
    # bigger intervals
    while (1 << j) <= n:

        # Compute minimum value for all
        # intervals with size 2^j
        i = 0
        while (i + (1 << j) - 1) < n:

            # For arr[2][10], we compare arr[lookup[0][7]]
            # and arr[lookup[3][10]]
            if (lookup[i][j - 1] <
                    lookup[i + (1 << (j - 1))][j - 1]):
                lookup[i][j] = lookup[i][j - 1]
            else:
                lookup[i][j] = \
                    lookup[i + (1 << (j - 1))][j - 1]

            i += 1
        j += 1


# Returns minimum of arr[L..R]
def query(L, R):
    # Find highest power of 2 that is smaller
    # than or equal to count of elements in
    # given range. For [2, 10], j = 3
    j = int(math.log2(R - L + 1))

    # Compute minimum of last 2^j elements
    # with first 2^j elements in range.
    # For [2, 10], we compare arr[lookup[0][3]]
    # and arr[lookup[3][3]],
    if lookup[L][j] <= lookup[R - (1 << j) + 1][j]:
        return lookup[L][j]

    else:
        return lookup[R - (1 << j) + 1][j]


#(A nlogn solution using sparse table)

t=int(input())
for _ in range(t):
    n,m,k=map(int,input().split())
    b=list(map(int,input().split()))

    lookup = [[0 for i in range(25)]
              for j in range(n+1)]

    a=[]
    for j in range(m):
        a.append(max(b[j],b[n-m+j]))

    buildSparseTable(a, m)

    ans=0
    if k<=(m-1):
        for i in range(k+1):
            ans=max(ans,query(i,i+m-k-1))


    else:
        for i in range(m):
            ans = max(ans, max(b[i], b[n - 1 - (m - 1 - (i))]))


    print(ans)

























