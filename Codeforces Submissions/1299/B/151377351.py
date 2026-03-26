def half(L,i,j): return ((L[i][0]+L[j][0])/2,(L[i][1]+L[j][1])/2)

def solv(n):
    if n%2: return 'NO'
    L = [list(map(int,input().split())) for _ in range(n)]
    h = n//2
    X = [half(L,i,i+h) for i in range(h)]
    for i in range(1,h):
        if X[i][0]!=X[0][0] or X[i][1]!=X[0][1]: return 'NO'
    return 'YES'

print(solv(int(input())))

