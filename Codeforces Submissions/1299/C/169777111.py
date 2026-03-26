import sys, random
input = lambda : sys.stdin.readline().rstrip()


write = lambda x: sys.stdout.write(x+"\n"); writef = lambda x: print("{:.12f}".format(x))
debug = lambda x: sys.stderr.write(x+"\n")
YES="Yes"; NO="No"; pans = lambda v: print(YES if v else NO); INF=10**18
LI = lambda : list(map(int, input().split())); II=lambda : int(input())
def debug(_l_):
    for s in _l_.split():
        print(f"{s}={eval(s)}", end=" ")
    print()
def dlist(*l, fill=0):
    if len(l)==1:
        return [fill]*l[0]
    ll = l[1:]
    return [dlist(*ll, fill=fill) for _ in range(l[0])]

from collections import deque
class CHT:
    """傾きが単調減少かつ評価点が単調増加のときの最小値クエリ
    """
    def __init__(self):
        self.q = deque()
    @staticmethod
    def _val(t,x):
        return t[0]*x+t[1]
    @staticmethod
    def _check(t1,t2,t3):
        return (t2[0]-t1[0]) * (t3[1]-t2[1]) >= (t2[1]-t1[1]) * (t3[0]-t2[0])
    def add(self, a, b):
        """a*x + bの追加
        """
        t = (a,b)
        while len(self.q)>=2 and self._check(self.q[-2], self.q[-1], t):
            # 追加する線分と最後から2番めの線分のCHだけで凸包になる
            self.q.pop()
        self.q.append(t)
    def query(self, x):
        """a*x+bの最小値を返す
        """
        while len(self.q)>=2 and self._val(self.q[0], x) >= self._val(self.q[1], x):
            self.q.popleft()
        return self._val(self.q[0], x)
    
n = int(input())
a = list(map(int, input().split()))
cum = [0]
for v in a:
    cum.append(cum[-1]+v)
ch = CHT()
for i in range(n+1):
    ch.add(-i, cum[i])
ans = [0]*n
a0,b0 = ch.q.popleft()
for i in range(len(ch.q)):
    a,b = ch.q.popleft()
#     print(a,b)
    x = -(b0-b)/(a0-a)
    for ind in range(-a0, -a):
        ans[ind] = x
    a0 = a
    b0 = b
write("\n".join(map(str, ans)))