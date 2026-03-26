import sys
input = sys.stdin.buffer.readline 

def process(A):
    n = len(A)
    L = []
    for i in range(n):
        l, r = A[i]
        L.append([l, 0, i])
        L.append([r, 1, i])
    L.sort()
    curr = set([])
    L2 = [[0, None]]
    for I in range(2*n):
        x, t, i = L[I]
        if t==0:
            curr.add(i)
        else:
            curr.remove(i)
        if len(curr)==1:
            R = curr.pop()
            curr.add(R)
        else:
            R = None
        L2.append([len(curr), R])
    my_max = 0
   # print(L2)
    d = {}
    m = len(L2)
    zero_count = 0
    for i in range(1, m-1):
        if L2[i][0]==1:
            my_max = max(my_max, 1)
            x = L2[i][1]
            a1, a2 = L2[i-1]
            b1, b2 = L2[i+1]
            if a1 > 0 and b1 > 0:
                if x not in d:
                    d[x] = 0
                d[x]+=1
        elif L2[i][0]==0:
            zero_count+=1
        else:
            my_max = max(my_max, L2[i][0])
    if len(d)==0:
        if my_max > 1:
            print(zero_count+1)
        else:
            print(zero_count)
    else:
        print(zero_count+max(d.values())+1)
                    
            
t = int(input())
for i in range(t):
    n = int(input())
    A = []
    for j in range(n):
        l, r = [int(x) for x in input().split()]
        A.append([l, r])
    process(A)