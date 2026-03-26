from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

d = dict()
for i in range(31):
    d[(1 << i)] = i

def answer():

    count = [0 for i in range(61)]
    for i in range(m):
        count[d[a[i]]] += 1

    if(sum(a) < n):return -1

    ans = 0
    for i in range(60):

        if(n >> i & 1):
            if(count[i] > 0):
                count[i] -= 1
            else:

                j = i
                while(count[j] == 0):
                    count[j] += 1
                    j += 1
                    ans += 1

                count[j] -= 1
                count[i] -= 1


        count[i + 1] += count[i] // 2

    return ans


for T in range(int(input())):

    n , m = inp()
    a = sorted(inp())

    print(answer())

    
