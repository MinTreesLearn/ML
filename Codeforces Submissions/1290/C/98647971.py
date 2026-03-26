import sys

def find(x):
    if x == pre[x]:
        return x
    else:
        pre[x]=find(pre[x])
        return pre[x]

def merge(x,y):
    x = find(x)
    y = find(y)
    if x != y:
        pre[x] = y
        siz[y] +=siz[x]

def cal(x):
    return min(siz[find(x)],siz[find(x+k)])

def Solve(i):   
    global ans
    cant = col[i][0]
    if cant == 2:
        x = col[i][1]
        y = col[i][2]
        if S[i] == 1:
            if find(x) == find(y):
                return
            ans -=cal(x) + cal(y)
            merge(x,y)
            merge(x+k,y+k)
            ans +=cal(x)
        else:
            if find(x) == find(y+k):
                return
            ans -=cal(x)+cal(y)
            merge(x,y+k)
            merge(x+k,y)
            ans +=cal(x)    
    elif cant == 1:
        x = col[i][1]
        if S[i] == 1:
            if find(x) == find(0):
                return
            ans -=cal(x)
            merge(x,0)
            ans +=cal(x)
        else:
            if find(x+k) == find(0):
                return
            ans -=cal(x)
            merge(x+k,0)
            ans +=cal(x)    



n,k = map(int,input().split())
S = [1]+list(map(int,list(sys.stdin.readline().strip())))
    
col = [[0 for _ in range(3)] for _ in range(n+2)]
pre = [i for i in range(k*2+1)]
siz = [0 for _ in range(k*2+1)]
ans = 0

for i in range(1,k+1):
    c = sys.stdin.readline()
    c = int(c)
    conjunto = [1]+list(map(int,list(sys.stdin.readline().split())))
    for j in range(1,len(conjunto)):
        x = conjunto[j]                        
        col[x][0] = col[x][0]+1
        col[x][col[x][0]] = i


for i in range(1,k+1):
    siz[i]=1
siz[0]=3*10e5

for i in range(1,n+1):    
    Solve(i)
    print(ans)
