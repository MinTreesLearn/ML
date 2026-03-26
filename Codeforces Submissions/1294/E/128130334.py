import sys
input = sys.stdin.readline
from collections import defaultdict 

def main():
    n,m = map(int,input().split())
    A = [list(map(int,input().split())) for _ in range(n)]
    for i in range(n):
        for j in range(m):
            A[i][j] -= 1
    if n == m == 1:
        if A[0][0] == 0:
            print(0)
        else:
            print(1)
    ans = 0
    for j in range(m):
        dic = defaultdict(int)
        for i in range(n):
            #print(i,j,A[i][j],-j)
            if (A[i][j] - j) % m != 0: continue
            r = (A[i][j] - j) // m
            if r >= n: continue
            move = (i + n - r) % n
            #print(i,j,A[i][j],r,move)
            dic[move] += 1
        #print(dic)
        req = n #change all
        for k,v in dic.items():
            temp = k + n - v
            req = min(req, temp)
        ans += req
    print(ans)

        
if __name__ == "__main__":
    main()