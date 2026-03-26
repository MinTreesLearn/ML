from collections import defaultdict
from string import ascii_lowercase
test=int(input())
for _ in range(test):
    string=list(input())
    value=set(string)
    graph=defaultdict(set)
    inDegree=defaultdict(int)
    x=string[0]
    inDegree[x]=0
    for i in range(1,len(string)):
        if string[i] not in graph[x]:
            inDegree[x]+=1
        graph[x].add(string[i])
        if x not in graph[string[i]]:
            inDegree[string[i]]+=1
        graph[string[i]].add(x)
        x=string[i]
    level=[]
    visited=set()
    for i in inDegree:
        if inDegree[i]==1 or inDegree[i]==0:
            level.append(i)
            visited.add(i)
            break
    ans=[]

    while level:
        node=level.pop()
        ans.append(node)
        for val in graph[node]:
            if val not in visited:
                visited.add(val)
                inDegree[val]-=1
                if inDegree[val]==1 or inDegree[val]==0:
                    level.append(val)

    if len(value)==len(ans):
        print("YES")
        for c in ascii_lowercase:
            if c not in ans:
                ans.append(c)
        print("".join(ans))
    else:
        print("NO")
    