def process(M):
    n = len(M)
    m = len(M[0])
    answer = 0
    for j in range(1, m+1):
        d = {}
        for i in range(n):
            entry = M[i][j-1]
            if entry % m == j % m and entry <= n*m:
                if j < m:
                    entry1 = entry//m
                else:
                    entry1 = entry//m-1
                entry1 = (i-entry1) % n
                if entry1  not in d:
                    d[entry1] = 0
                d[entry1]+=1
        moves = n
        for x in d:
            moves = min(moves, n-d[x]+x)
        answer+=moves
    return answer

n, m = [int(x) for x in input().split()]
M = []
for i in range(n):
    row = [int(x) for x in input().split()]
    M.append(row)
print(process(M))