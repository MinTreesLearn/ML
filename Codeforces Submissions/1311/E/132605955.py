import sys, collections, math,bisect
input = sys.stdin.readline
for _ in range(int(input())):
    n,d = map(int,input().split())
    # 考虑单链
    # 分别记录每个节点的深度,孩子节点个数,父节点
    depth = [0] + list(range(n))
    child = [0] + [1] * (n - 1) + [0]
    fa = [-1,-1] + list(range(1,n))
    cur_d = sum(depth)
    if d > cur_d:
        print('NO')
        continue

    for i in range(n,0,-1):
        # 每次将一个叶子节点向上移动
        if child[i] != 0:
            continue
        child[fa[i]] -= 1
        # 记录新的父节点,以及减少的节点深度
        node,diff = -1,0
        for j in range(1,n + 1):
            if i != j and child[j] < 2 and cur_d - d >= depth[i] - depth[j] - 1 and depth[i] - depth[j] - 1 > diff:
                diff = depth[i] - depth[j] - 1
                node = j
        if node == -1:
            break
        else:
            child[node] += 1
            fa[i] = node
            depth[i] = depth[node] + 1
            cur_d -= diff
    if cur_d == d:
        print('YES')
        print(*fa[2:])
    else:
        print('NO')












