from sys import stdin , setrecursionlimit
input = stdin.readline
setrecursionlimit(3001)
inp = lambda : list(map(int,input().split()))

def dfs(p):

    global ansfound

    subtree = []
    for i in child[p]:
        subtree += dfs(i)

    if(c[p - 1] > len(subtree)):
        ansfound = False
    else:
        
        if(c[p - 1] == 0):

            ans[p] = 1
            for i in range(1 , n + 1):
                ans[i] += 1
        else:

            take = []
            for i in subtree:
                take.append(ans[i])

            take.sort()
            
            ans[p] = take[c[p - 1] - 1] + 1
            for i in range(1 , n + 1):
                if(i == p):continue
                
                if(ans[i] >= ans[p]):
                    ans[i] += 1

    subtree.append(p)
    return subtree
 
for T in range(1):

    n = int(input())

    child = [[] for i in range(n + 1)]
    c = []
    for i in range(n):
        p , count = inp()
        c.append(count)
        
        if(p == 0):
            root = i + 1
            continue

        child[p].append(i + 1)
        

    timer = 0
    ans = [i for i in range(n + 1)]

    ansfound = True  
    dfs(root)

    if(ansfound):
        print("YES")
        print(*ans[1:])
    else:
        print("NO")
