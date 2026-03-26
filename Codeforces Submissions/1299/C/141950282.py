import sys
input = sys.stdin.buffer.readline 

def process(A):
    n = len(A)
    curr = [[A[0], 1]]
    for i in range(1, n):
        ai = A[i]
        curr.append([ai, 1])
        while len(curr) > 1:
            ai, l = curr[-1]
            aj, j = curr[-2]
            if l*aj >= j*ai:
                ai, l = curr.pop()
                curr[-1] = [aj+ai, j+l]
            else:
                break
    answer = []
    for ai, i in curr:
        for j in range(i):
            answer.append(ai/i)
    return answer

n = int(input())
A = [int(x) for x in input().split()]
for x in process(A):
    sys.stdout.write(str(x)+'\n')