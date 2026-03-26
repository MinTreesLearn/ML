from sys import stdin
input=lambda :stdin.readline()[:-1]

class LowestCommonAncestor:
    """ <O(n), O(log(n))> """

    def __init__(self, G: "隣接リスト", root: "根", parents):
        from collections import deque
        self.n = len(G)
        self.tour = [0] * (2 * self.n - 1)
        self.depth_list = [0] * (2 * self.n - 1)
        self.id = [-1] * self.n
        self.dfs(G, root, parents)
        self._rmq_init(self.depth_list)

    def _rmq_init(self, arr):
        n = self.mod = len(arr)
        self.seg_len = 1 << (n - 1).bit_length()
        self.seg = [self.n * n] * (2 * self.seg_len)
        seg = self.seg
        for i, e in enumerate(arr):
            seg[self.seg_len + i] = n * e + i
        for i in range(self.seg_len - 1, 0, -1):
            seg[i] = min(seg[2 * i], seg[2 * i + 1])

    def _rmq_query(self, l, r):
        """最小値となるindexを返す"""
        l += self.seg_len; r += self.seg_len
        res = self.n * self.mod
        seg = self.seg
        while l < r:
            if r & 1:
                r -= 1
                res = min(res, seg[r])
            if l & 1:
                res = min(res, seg[l])
                l += 1
            l >>= 1; r >>= 1
        return res % self.mod

    def dfs(self, G, root, parents):
        """ 非再帰で深さ優先探索を行う """
        id = self.id
        tour = self.tour
        depth_list = self.depth_list
        v = root
        it = [0] * self.n
        visit_id = 0
        depth = 0
        while v != -1:
            if id[v] == -1:
                id[v] = visit_id
            tour[visit_id] = v
            depth_list[visit_id] = depth
            visit_id += 1
            g = G[v]
            if it[v] == len(g):
                v = parents[v]
                depth -= 1
                continue
            if g[it[v]] == parents[v]:
                it[v] += 1
                if it[v] == len(g):
                    v = parents[v]
                    depth -= 1
                    continue
                else:
                    child = g[it[v]]
                    it[v] += 1
                    v = child
                    depth += 1
            else:
                child = g[it[v]]
                it[v] += 1
                v = child
                depth += 1

    def lca(self, u: int, v: int) -> int:
        """ u と v の最小共通祖先を返す """
        l, r = self.id[u], self.id[v]
        if r < l:
            l, r = r, l
        q = self._rmq_query(l, r + 1)
        return self.tour[q]

    def dist(self, u: int, v: int) -> int:
        """ u と v の距離を返す """
        lca = self.lca(u, v)
        depth_u = self.depth_list[self.id[u]]
        depth_v = self.depth_list[self.id[v]]
        depth_lca = self.depth_list[self.id[lca]]
        return depth_u + depth_v - 2 * depth_lca

n=int(input())
edge=[[] for i in range(n)]
edge_id={}
for i in range(n-1):
  x,y=map(lambda x:int(x)-1,input().split())
  edge[x].append(y)
  edge[y].append(x)
  edge_id[(x<<20)+y]=i
  edge_id[(y<<20)+x]=i


par=[-1]*n
todo=[(0,-1)]
while todo:
  v,p=todo.pop()
  for u in edge[v]:
    if p!=u:
      par[u]=v
      todo.append((u,v))

lca=LowestCommonAncestor(edge,0,par)

q=int(input())
c=[]
for i in range(q):
  x,y,g=map(int,input().split())
  c.append((g,x-1,y-1))

c.sort(reverse=True)

def find_pass(frm,to):
  L=lca.lca(frm,to)
  now=frm
  pass1=[]
  while now!=L:
    p=par[now]
    pass1.append(edge_id[(now<<20)+p])
    now=p

  now=to
  pass2=[]
  while now!=L:
    p=par[now]
    pass2.append(edge_id[(now<<20)+p])
    now=p
  
  return pass1+pass2[::-1]

color=[-1]*(n-1)
for g,x,y in c:
  flag=False
  for id in find_pass(x,y):
    if color[id]==-1 or color[id]==g:
      color[id]=g
      flag=True
  if not flag:
    print(-1)
    exit()

for i in range(n-1):
  if color[i]==-1:
    color[i]=10**6
print(*color)