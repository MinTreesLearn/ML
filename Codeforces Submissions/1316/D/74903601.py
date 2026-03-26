import sys
# def input(): return sys.stdin.readline()[:-1]
def input(): return sys.stdin.buffer.readline()[:-1]

def print(*values, end='\n'): sys.stdout.write(' '.join([str(x) for x in values]) + end) 
from collections import deque


def main():
    n = int(input())

    res = [[''] * n for _ in range(n)]

    data = [[None] * n for _ in range(n)]


    q = deque()
    cnt = 0
    for i in range(n):
        row = [int(x) - 1 for x in input().split()]
        for j in range(n):
            data[i][j] = (row[j * 2], row[j * 2 + 1])
            if (i, j) == data[i][j]:
                q.append((i, j))
                res[i][j] = 'X'
                

    
    while q:
        cnt += 1
        i, j = q.popleft()
        if 0 <= i + 1 < n and 0 <= j < n and data[i+1][j] == data[i][j] and not res[i+1][j]:
            res[i + 1][j] = 'U'
            q.append((i + 1, j))
        if 0 <= i - 1 < n and 0 <= j < n and data[i-1][j] == data[i][j] and not res[i-1][j]:
            res[i - 1][j] = 'D'
            q.append((i - 1, j))
        if 0 <= i < n and 0 <= j + 1 < n and data[i][j+1] == data[i][j] and not res[i][j+1]:
            res[i][j + 1] = 'L'
            q.append((i, j + 1))
        if 0 <= i < n and 0 <= j - 1 < n and data[i][j-1] == data[i][j] and not res[i][j-1]:
            res[i][j - 1] = 'R'
            q.append((i, j - 1))


    for i in range(n):
        for j in range(n):
            if data[i][j] == (-2, -2):
                cnt += 1
                if 0 <= i + 1 < n and 0 <= j < n and data[i+1][j] == (-2, -2):
                    res[i][j] = 'D'
                elif 0 <= i - 1 < n and 0 <= j < n and data[i-1][j] == (-2, -2):
                    res[i][j] = 'U'
                elif 0 <= i < n and 0 <= j + 1 < n and data[i][j+1] == (-2, -2):
                    res[i][j] = 'R'
                elif 0 <= i < n and 0 <= j - 1 < n and data[i][j-1] == (-2, -2):
                    res[i][j] = 'L'
                else:
                    print("INVALID")
                    exit()

    if cnt != n * n:
        print("INVALID")
        exit()

    print('VALID')
    for e in res:
        print(''.join(e))


main()
