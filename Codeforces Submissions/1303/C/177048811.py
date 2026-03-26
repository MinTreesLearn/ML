import sys
import threading
from math import inf
from bisect import *
from collections import defaultdict, deque
def li(): return list(map(int, input().split()))
def nn(): return int(input().split())
def w(): return input()

def solve():
    word = input()
    if len(word) == 1:
        print("YES")
        print("".join([chr(x) for x in range(ord('a'), ord('z') + 1)]))
        return
    graph = defaultdict(set)
    for i in range(len(word)-1):
        cur = word[i]
        next = word[i+1]
        graph[cur].add(next)
        graph[next].add(cur)
        
        if len(graph[cur])>2:
            return print("NO")
    leaf = [char for char in graph if len(graph[char])<=1]
    if len(leaf)<2:
        return print("NO")
    
    ans = []
    
    queue = deque([leaf[0]])
    
    
    while queue:
        top = queue.popleft()
        ans.append(top)
        for nbr in graph[top]:
            graph[nbr].remove(top)
            queue.append(nbr)
    
    for char in ([chr(i) for  i in range(ord('a'), ord('z')+1)]):
        if char not in ans:
            ans.append(char)
    print("YES")
    print(''.join(ans))
    return
            
        
 
def main():
    t = int(input())
    for  i in range(t):
        solve()
            
        
        
        
main()

# sys.setrecursionlimit(1<<30)
# threading.stack_size(1<<27)
# main_thread=threading.Thread(target=main)
# main_thread.start()
# main_thread.join()