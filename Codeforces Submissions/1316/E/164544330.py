import sys
input = sys.stdin.buffer.readline 

def process(A, S, k):
    n = len(A)
    p = len(S[0])
    pairs = []
    for x in range(2**p-1, -1, -1):
        b = sum(map(int, bin(x)[2:]))
        for j in range(p):
            if x&(2**j)==0:
                pairs.append([x, j, b])
    A2 = []
    for i in range(n):
        row = [A[i]]
        for j in range(p):
            row.append(S[i][j])
        A2.append(row)
    A2.sort(reverse=True)
    aud_sum = 0
    for i in range(k):
        aud_sum+=A2[i][0]
    d = [aud_sum for i in range(2**p)]
   # print(A2)
    for i in range(n):
      #  print(A2[i], d, "Before")
        for x, j, b in pairs:
            entry1 = d[x]+A2[i][j+1]
            """
            we are currently using
            the first k+b things one way or another
            
            """
            if i <= k+b:
                entry1-=A2[i][0]
                entry1+=A2[k+b][0]
           # print(x, j, b, entry1)
            d[x+2**j] = max(d[x+2**j], entry1)
       # print(d, "After")
    print(d[2**p-1])
     
                
n, p, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
S = []
for i in range(n):
    row = [int(x) for x in input().split()]
    S.append(row)
process(A, S, k)