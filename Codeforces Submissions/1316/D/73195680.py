from sys import stdin, stdout
import __pypy__

def main():
    n = int(stdin.readline())
    matrix = [[]]
    ans = [[]]
    s = []
    cnt = 0
    for i in range(n):
        matrix.append([])
        matrix[-1].append((-9,-9))
        ans.append([])
        ans[-1].append("Z")
        temp = list(map(int, stdin.readline().split()))
        for j in range(n):
            x,y = temp[j*2], temp[j*2+1]
            matrix[-1].append((x,y))
            if i+1 == x and j+1 == y:
                s.append((x,y))
                ans[-1].append("X")
            else:
                ans[-1].append("Z")
    while s:
        x,y = s.pop()
        cnt += 1
        if 0 < x-1 <= n and ans[x-1][y] == 'Z' and matrix[x-1][y] == matrix[x][y]:
            s.append((x-1,y))
            ans[x-1][y] = 'D'
        if 0 < x+1 <= n and ans[x+1][y] == 'Z' and matrix[x+1][y] == matrix[x][y]:
            s.append((x+1,y))
            ans[x+1][y] = 'U'
        if 0 < y-1 <= n and ans[x][y-1] == 'Z' and matrix[x][y-1] == matrix[x][y]:
            s.append((x,y-1))
            ans[x][y-1] = 'R'
        if 0 < y+1 <= n and ans[x][y+1] == 'Z' and matrix[x][y+1] == matrix[x][y]:
            s.append((x,y+1))
            ans[x][y+1] = 'L'
    for i in range(1,n+1):
        for j in range(1,n+1):
            if matrix[i][j] == (-1,-1) and ans[i][j] =='Z':
                x,y = i,j
                if 0 < x-1 <= n and matrix[x-1][y] == (-1, -1):
                    cnt+=1
                    ans[x][y] = 'U'
                elif 0 < x+1 <= n and matrix[x+1][y] == (-1, -1):
                    cnt+=1
                    ans[x][y] = 'D'
                elif 0 < y-1 <= n and matrix[x][y-1] == (-1, -1):
                    cnt+=1
                    ans[x][y] = 'L'
                elif 0 < y+1 <= n and matrix[x][y+1] == (-1, -1):
                    cnt+=1
                    ans[x][y] = 'R'
                else:
                    stdout.write("INVALID")
                    return
    if n*n != cnt:
        stdout.write("INVALID")
        return
    stdout.write("VALID\n")
    res = __pypy__.builders.StringBuilder()
    for i in range(1,n+1):
        for j in range(1,n+1):
            res.append("%s"%(ans[i][j]))
        res.append("\n")
    stdout.write(res.build())
    
main()
    
            