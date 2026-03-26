from collections import defaultdict,deque
n = int(input())



for _ in range(n):
    graph = defaultdict(set)
    degrees = defaultdict(int)
    visited = set()

    edges = input()
    graph[edges[0]] = set()
    degrees[edges[0]] = 0
    for i in range(1,len(edges)):
        u,v = edges[i-1],edges[i]
        if (u,v) not in visited and (v,u) not in visited:
            graph[u].add(v)
            graph[v].add(u)
            degrees[u]+=1
            degrees[v]+=1
            visited.add((u,v))
            visited.add((v,u))
    flag = False 

    for node,degree in degrees.items():
        if degree >= 3:
            flag = True
            break 

    q = deque([char for char in degrees if degrees[char]<2])
    order = []
    visited = set()

    while q:
        char = q.popleft()
        if char in visited:
            continue 
        order.append(char)
        visited.add(char)

        for adjChar in graph[char]:
            graph[adjChar].remove(char)
            degrees[adjChar]-=1

            if degrees[adjChar]<=1:
                q.appendleft(adjChar)

    if len(order)!=len(graph) or flag == True:
        print("NO")
    else:
        for charOrd in range(ord('a'),ord('z')+1):
            char = chr(charOrd)
            if char not in graph:
                order.append(char)
        
        print("YES")
        print("".join(order))




        