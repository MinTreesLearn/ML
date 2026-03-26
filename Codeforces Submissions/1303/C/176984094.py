import sys
sys.setrecursionlimit(200000)
import math
from collections import Counter
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
from functools import lru_cache
import heapq 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s)-1]))
def invr():
    return(map(int,input().split()))
 
 
    
    
def main():
    
   
    for _ in range(inp()):
        
        password = input().rstrip()
        graph = defaultdict(list)
        q = deque()
        degree = [0 for i in range(26)]
        
        max_degree = 0
        
        for i in range(len(password)):
            
            if i + 1 <len(password) and password[i+1] not in graph[password[i]]:
                
                graph[password[i]].append(password[i+1])
                degree[ord(password[i])-ord("a")] = max(degree[ord(password[i])-ord("a")],len(graph[password[i]]))
                
            if i-1 >= 0 and password[i-1] not in graph[password[i]]:
                
                graph[password[i]].append(password[i-1])
                degree[ord(password[i])-ord("a")] = max(degree[ord(password[i])-ord("a")],len(graph[password[i]]))
                
            max_degree = max(max_degree,degree[ord(password[i])-ord("a")] )
            
        if max_degree > 2:
            print("NO")
            continue
        s = []
        
        def dfs(element):
            
            s.append(element)
            degree[ord(element)-ord("a")] = math.inf
            
            
                
            for neigb in graph[element]:
                
                if degree[ord(neigb)-ord("a")] != math.inf  :
                    
                     dfs(neigb)
                    
            
            
        for i in range(len(degree)):
            
            if degree[i] == 1:
                
                dfs(chr(ord("a")+i))
                    
            
        
        
            
        
        for i in range(len(degree)):
            if degree[i] == 0:
                s.append(chr(ord("a")+i))
                
        if len(s) == 26:
            
            print("YES")
            print("".join(s))
            
        else:
            
            print("NO")
                
            
                    
            
                
            
    
   
        
    
                
    
    
    
 
main()