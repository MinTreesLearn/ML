import sys
input = sys.stdin.buffer.readline 

def process(S, P):
    n = len(S)
    m = len(P)
    counts = [0 for i in range(n+1)]
    for pi in P:
        counts[pi]+=1
    counts[n]+=1
    totals = [0 for i in range(n+1)]
    total = 0
    for i in range(n, -1, -1):
        total+=counts[i]
        totals[i] = total
    answer = [0 for i in range(26)]
    for i in range(1, n+1):
        si = ord(S[i-1])-ord('a')
        answer[si]+=totals[i]
    answer = ' '.join(map(str, answer))
    sys.stdout.write(f'{answer}\n')
    return

t = int(input())
for i in range(t):
    n, m = [int(x) for x in input().split()]
    S = input().decode().strip()
    P = [int(x) for x in input().split()]
    process(S, P)