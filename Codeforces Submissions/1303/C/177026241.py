from collections import defaultdict, deque
from string import ascii_lowercase


for _ in range(int(input())):
    password = input()
        
    graph = defaultdict(set)
    for i in range(1,len(password)):
        graph[password[i - 1]].add(password[i])
        graph[password[i]].add(password[i - 1])
    
    in_degree = {ch: len(graph[ch]) for ch in ascii_lowercase}
    # print(in_degree)
    if any(map(lambda x: in_degree[x] > 2, ascii_lowercase)):
        print("NO")
        continue

    visited = set()

    res = []

    q = deque([])

    for k,v in in_degree.items():
        if v == 1:
            q.append(k)
            visited.add(k)
            break
    while q:
        val = q.popleft()
        res.append(val)
        for neighbour in graph[val]:
            if neighbour not in visited:
                q.append(neighbour)
                visited.add(neighbour)
    
    if len(password) == 1:
        visited.add(password[0])
        res.append(password[0])
        
    if len(visited) != len(set(password)):
        print("NO")

    else:
        # print(res)
        for ch in ascii_lowercase:
            if ch not in res:
                res.append(ch)

        print("YES")
        print("".join(res))