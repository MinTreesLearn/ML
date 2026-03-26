import sys
input = sys.stdin.buffer.readline 
output = sys.stdout.write 
def adj(x, y, n, answer, T):
    if T:
        return [(direct, flipped, x+dx, y+dy) for 
    (direct, flipped, dx, dy) in [('D', 'U', 1, 0), 
    ('U', 'D', -1, 0), ('R', 'L', 0, 1), 
    ('L','R', 0, -1)] if 0 <= x+dx <= n-1 and 0 <= y+dy <= n-1 and answer[x+dx][y+dy] is None ]
    else:
        return [(direct, flipped, x+dx, y+dy) for 
    (direct, flipped, dx, dy) in [('D', 'U', 1, 0), 
    ('U', 'D', -1, 0), ('R', 'L', 0, 1), 
    ('L','R', 0, -1)] if 0 <= x+dx <= n-1 and 0 <= y+dy <= n-1]
 
def process(M):
    n = len(M)
    none_count = n*n
    answer = [[None for i in range(n)] for j in range(n)]
    def block_process(i, j, none_count):
        answer[i][j] = 'X'
        none_count-=1
        start = [(i, j)]
        while len(start) > 0:
            next_s = []
            for i2, j2 in start:
                for (direct, flipped, i3, j3) in adj(i2, j2, n, answer, True):
                    if (M[i3][2*j3]-1, M[i3][2*j3+1]-1)==(i, j):
                        answer[i3][j3] = flipped
                        none_count-=1
                        next_s.append((i3, j3))
            start = next_s 
        return none_count
    for i in range(n):
        for j in range(n):
            xi, yi = M[i][2*j]-1, M[i][2*j+1]-1
            if (xi, yi) != (-2, -2):
                if (M[xi][2*yi]-1, M[xi][2*yi+1]-1) != (xi, yi):
                    return [False, None]
                if answer[xi][yi] is None:
                    none_count = block_process(xi, yi, none_count)
    if none_count==0:
        return [True, answer]
    for i in range(n):
        for j in range(n):
            if answer[i][j] is None:
                if (M[i][2*j]-1, M[i][2*j+1]-1) != (-2, -2):
                    return [False, None]
                L = adj(i, j, n, answer, False)
                pair = None
                cycle_linked = False
                for (direct, flipped, i3, j3) in L:
                    if answer[i3][j3] is not None and (M[i3][2*j3], M[i3][2*j3+1])==(-1, -1):
                        answer[i][j] = direct 
                        cycle_linked = True
                    elif answer[i3][j3] is None:
                        pair = (direct, flipped, i3, j3)
                if not cycle_linked:
                    if pair is None:
                        return [False, None]
                    (direct, flipped, i3, j3) = pair
                    answer[i][j] = direct
                    answer[i3][j3] = flipped
                for (direct, flipped, i4, j4) in L:
                    if answer[i4][j4] is None:
                        answer[i4][j4] = flipped
    return [True, answer]
    
 
n = int(input())
M = []
for i in range(n):
    row =list(map(int, sys.stdin.readline().split()))
    M.append(row)
a1, a2 = process(M)
if a1:
    print('VALID')
    for row in a2:
        output(''.join(row)+'\n')
else:
    print('INVALID')