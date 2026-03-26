# ======== author: kuanc (@kuantweets) | created: 08/04/22 01:25:01 ======== #
from sys            import stdin,  stderr, stdout, setrecursionlimit
from bisect         import bisect_left, bisect_right
from collections    import defaultdict, deque, Counter
from itertools      import accumulate, combinations, permutations, product
from functools      import lru_cache, cmp_to_key, reduce
from heapq          import heapify, heappush, heappop, heappushpop, heapreplace
# from pypyjit        import set_param
# set_param("max_unroll_recursion=-1")
# setrecursionlimit(300005)
INF   = 1 << 60
MOD   = 998244353 + 1755654
input = lambda: stdin.readline().rstrip("\r\n")
dbg   = lambda *A, **M: stderr.write("\033[91m" + \
        M.get("sep", " ").join(map(str, A)) + M.get("end", "\n") + "\033[0m")
# ============================ START OF MY CODE ============================ #

def bootstrap(f):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if isinstance(to, type((lambda: (yield))())):
                stack.append(to)
                to = next(to)
            else:
                stack.pop()
                if not stack:
                    break
                to = stack[-1].send(to)
        return to
    stack = []
    return wrappedfunc

def solve(_tc):
    @bootstrap
    def dfs(node, prev):
        C[node] = 1 if A[node] == 1 else -1
        for neigh in adj[node]:
            if neigh == prev:
                continue
            yield dfs(neigh, node)
            C[node] += max(0, C[neigh])
        yield

    @bootstrap
    def dfs2(node, prev):
        for neigh in adj[node]:
            if neigh == prev:
                continue
            C[neigh] += max(0, C[node] - max(0, C[neigh]))
            yield dfs2(neigh, node)
        yield

    N = int(input())
    A = list(map(int, input().split()))

    adj = defaultdict(list)
    for _ in range(N - 1):
        a, b = map(int, input().split())
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)

    C = [0 for _ in range(N)]
    dfs(0, -1)
    dfs2(0, -1)

    print(*C)


if __name__ == "__main__":
    # _tcs = int(input())
    for _tc in range(1, vars().get("_tcs", 1) + 1):
        dbg("=== Case {} ===".format(str(_tc).rjust(2)))
        solve(_tc)
