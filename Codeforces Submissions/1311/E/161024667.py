import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,d=map(int,input().split())
    max=n*(n-1)//2
    if d>max:
        print('NO')
        continue
    dif=max-d
    tree=[1]*n
    move_to,move_from=1,n-1
    while move_from>move_to:
        if dif>move_from-move_to:
            tree[move_from]-=1
            tree[move_to]+=1
            dif-=move_from-move_to
        else:
            tree[move_from]-=1
            tree[move_from-dif]+=1
            dif=0
            break
        if tree[move_to]==2**move_to:
            move_to+=1
        if tree[move_from]==0:
            move_from-=1
    if dif>0:
        print('NO')
        continue
    print('YES')
    ans,ind=[[1]],2
    for i in range(1,n):
        ti=[]
        for j in range(tree[i]):
            ti.append(ind)
            ind+=1
        ans.append(ti)
    answ=[]
    for i in range(1,n):
        for j in range(tree[i]):
            answ.append(ans[i-1][j//2])
    print(*answ)


