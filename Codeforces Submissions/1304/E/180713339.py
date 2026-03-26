#Mock contest 4 Round #4
#Problem H
import sys, collections, functools
input = lambda: sys.stdin.readline()[:-1]
get_int = lambda: int(input())
get_int_iter = lambda: map(int, input().split())
get_int_list = lambda: list(get_int_iter())
flush = lambda: sys.stdout.flush()

#Hi

#DEBUG
DEBUG = False
def debug(*args):
    if DEBUG:
        print(*args)

n = get_int()
edges = collections.defaultdict(list)
for _ in range(n-1):
    u,v = map(lambda x:x-1,get_int_iter())
    edges[u].append(v)
    edges[v].append(u)
depth = [0]*n
parent1 = [-1] + [-2]*(n-1)
todo = [0]
while todo:
    curr = todo.pop()
    for node in edges[curr]:
        if parent1[node] == -2:
            parent1[node] = curr
            depth[node] = depth[curr]+1
            todo.append(node)
max_depth = max(depth)
parent_lists = [parent1]
up = 2
while up <= max_depth:
    prev = parent_lists[-1]
    parent_up = [-1]*n
    for val in range(n):
        if depth[val] >= up:
            parent_up[val] = prev[prev[val]]
    up *= 2
    parent_lists.append(parent_up)

def get_bits(n):
    return len(bin(n)) - 3 # 0 for 0b1, 1 for 0b10, 2 for 0b110 etc.

@functools.lru_cache(maxsize=100000)
def path_length(a,b):
    da,db = depth[a],depth[b]
    if da < db:
        a,b = b,a
        da,db = db,da
    ans = 0
    if da > db:
        ans = da - db
        while da > db:
            a = parent_lists[get_bits(da-db)][a]
            da = depth[a]
    #They are same depth now
    i = len(parent_lists)-1
    while True:
        if a == b:
            return ans
        
##        while parent_lists[i][a] == parent_lists[i][b]:
##            i += 1
        while i >= 0 and parent_lists[i][a] == parent_lists[i][b]:
            i -= 1
        if i == -1:
            return 2 + ans
        ans += 2 * (2 ** i)
        a = parent_lists[i][a]
        b = parent_lists[i][b]

q = get_int()
for _ in range(q):
    x,y,a,b,k = map(lambda x: x-1, get_int_iter())
    k += 1
    short_path = 1 + min(path_length(a,x)+path_length(b,y), path_length(a,y)+path_length(b,x))
    normal_path = path_length(a,b)
    debug(f"{[short_path,normal_path,k]}")
    if normal_path % 2 == k % 2 and normal_path <= k:
        print("YES")
    elif short_path % 2 == k % 2 and short_path <= k:
        print("YES")
    else:
        print("NO")
    debug()
    """
    if (depth[x] + depth[y]) % 2 == 1:
        #Cannot make parity switch
        if (depth[a] + depth[b] + k) % 2 == 1:
            print("NO")
            continue
        short = min(path_length(a,x)+1+path_length(b,y), path_length(a,y)+1+path_length(b,x), path_length(a,b))
        print("YES" if short <= k else "NO")
        continue
    if (depth[a] + depth[b]+ depth[x] + depth[y] + k) % 2 == 1:
        #Parity switch
        print("Parity")
        short = min(path_length(a,x)+path_length(b,y),path_length(a,y)+path_length(b,x))
    else:
        #No parity switch
        short = path_length(a,b)
    print("YES" if short <= k else "NO")
    """
