# でつoO(YOU PLAY WITH THE CARDS YOU'RE DEALT..)
import sys
def main(n, d):
    P = [0] + list(range(n - 1))
    C = [set() for _ in range(n)]
    for v in range(n - 1):
        C[v].add(v + 1)
    D = list(range(n))
    Vd = [set() for _ in range(n)]
    for v in range(n):
        Vd[v].add(v)
    L = [n - 1]
    # B = [0] * n

    s = (n - 1) * n // 2
    if d > s: return None
    while s > d:
        if not L: return None
        v = L.pop()
        if D[v] < 2: continue
        # if B[v]: continue
        for p in Vd[D[v] - 2]:
            if len(C[p]) == 2: continue
            s -= 1
            bp = P[v]
            C[bp].remove(v)
            if len(C[bp]) == 0: L.append(bp)
            P[v] = p
            C[p].add(v)
            Vd[D[v]].remove(v)
            D[v] -= 1
            Vd[D[v]].add(v)
            L.append(v)
            break
        # else:
        #     B[v] = 1

    return (P[i] + 1 for i in range(1, n))

if __name__ == '__main__':
    input = sys.stdin.readline
    T = int(input())
    for _ in range(T):
        n, d = map(int, input().split())
        ans = main(n, d)
        if ans is None:
            print('NO')
        else:
            print('YES')
            print(*ans)
