n,q=map(int,input().split())
grid=[]
for j in range(2):
    grid.append([0]*n)
co=0
for j in range(q):
    r,c=map(int,input().split())
    r-=1
    c-=1
    if grid[r][c]==0:
        grid[r][c]=1
        e=0
        if r==0:
            if c-1>=0:
                if grid[1][c-1]==1:
                    e+=1
            if grid[1][c]==1:
                e+=1
            if c+1<n:
                if grid[1][c+1]==1:
                    e+=1
        else:
            if c-1>=0:
                if grid[0][c-1]==1:
                    e+=1
            if grid[0][c]==1:
                e+=1
            if c+1<n:
                if grid[0][c+1]==1:
                    e+=1
        co+=e
    else:
        grid[r][c]=0
        e = 0
        if r == 0:
            if c - 1 >= 0:
                if grid[1][c - 1] == 1:
                    e += 1
            if grid[1][c] == 1:
                e += 1
            if c + 1 < n:
                if grid[1][c + 1] == 1:
                    e += 1
        else:
            if c - 1 >= 0:
                if grid[0][c - 1] == 1:
                    e += 1
            if grid[0][c] == 1:
                e += 1
            if c + 1 < n:
                if grid[0][c + 1] == 1:
                    e += 1
        co-=e
    if co==0:
        print("Yes")
    else:
        print("No")