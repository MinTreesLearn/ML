# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
import sys
input = sys.stdin.readline
from collections import defaultdict
from collections import Counter
from string import ascii_lowercase 
from functools import lru_cache
from collections import deque
import heapq

sys.setrecursionlimit(100000)
############ ---- Input Functions ---- ############
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

cases = inp()
for case in range(cases):
    loved = defaultdict(set)
    s = input().strip()
    if len(s) == 1:
        print("YES")
        print("xzytabcdefghijklmnopqrsuvw")
        continue
    
    test = False
    for i in range(len(s)-1):
        loved[s[i]].add(s[i+1])
        loved[s[i+1]].add(s[i])
        if len(loved[s[i]]) > 2 or len(loved[s[i+1]]) > 2:
            test = True
            break
    
    
    if test:
        print("NO")
        continue
    
    que = deque()
    ans = ""
    for key in loved:
        if len(loved[key]) == 1:
            que.append(key)
    
    # print(que)
    if len(que) == 0:
        print("NO")
        continue
    
    visited = set()
    def dfs(char):
        ans.append(char)
        for c in loved[char]:
            if c not in visited:
                visited.add(c)
                dfs(c)
    
    
    ans = []
    sest = set()
    for cs in que:
        if cs not in visited:
            visited.add(cs)
            dfs(cs)
        
            
    sth = "xzytabcdefghijklmnopqrsuvw"
    
    ans = "".join(ans)
    for j in ans:
        sest.add(j)
        
    for i in sth:
        if i not in sest:
            ans += i
            sest.add(i)
            
    print("YES")
    print(ans)
            
            
            
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    



