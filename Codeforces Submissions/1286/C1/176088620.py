import sys
input = sys.stdin.buffer.readline 


def convert(s):
    answer = [0 for i in range(26)]
    for c in s:
        answer[ord(c)-ord('a')]+=1
    return answer

def string_apply(t1, t2, f):
    answer = [f(t1[i], t2[i]) for i in range(26)]
    return answer
    
def convert2(t):
    if max(t)==1 and min(t)==0 and sum(t)==1:
        for i in range(26):
            if t[i]==1:
                return chr(i+ord('a'))
    return -1 

def process(n):
    L = []
    sys.stdout.write(f'? 1 {n}\n')
    sys.stdout.flush()
    for i in range(n*(n+1)//2):
        substring = input().decode().strip()
        L.append([convert(substring), 1])
    if n >= 2:
        sys.stdout.write(f'? 2 {n}\n')
        sys.stdout.flush()
        for i in range(n*(n-1)//2):
            substring = input().decode().strip()
            L.append([convert(substring), 2])
    L.sort()
    curr = [L[0][0], 0, 0]
    L2 = []
    for i in range(len(L)):
        if curr[0] < L[i][0]:
            L2.append(curr)
            curr = [L[i][0], 0, 0]
        t = L[i][1]
        curr[t]+=1
    L2.append(curr)
    final  = []
    for x in L2:
        if x[1] > x[2]:
            final.append(x[0])
    answer = [None for i in range(n)]
    answer[0] = convert2(final[0])
    for i in range(1, n):
        X = string_apply(final[i], final[i-1], lambda a, b: a-b)
        answer[i] = convert2(X)
    answer = ''.join(answer)
    sys.stdout.write(f'! {answer}\n')
    sys.stdout.flush()
    
n = int(input())
process(n)