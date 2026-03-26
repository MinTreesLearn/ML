import sys
input = sys.stdin.buffer.readline 

def process(B):
    n = len(B)
    d = {}
    for i in range(n):
        x = i-B[i]
        if x not in d:
            d[x] = [[], 0]
        d[x][0].append([i, B[i]])
        d[x][1]+=B[i]
    my_max = 0
    for x in d:
        my_max = max(my_max, d[x][1])
    return my_max

n = int(input())
B = [int(x) for x in input().split()]
print(process(B))