import sys
input = sys.stdin.buffer.readline
        
def process(n, d):
    if d > n*(n-1)//2:
        return ['NO', None]
    answer = [1]
    while True:
        if sum(answer)+2*answer[-1] <= n:
            answer.append(2*answer[-1])
        else:
            break
    answer.append(n-sum(answer))
    curr = sum([i*answer[i] for i in range(len(answer))])
    if d < curr:
        return ['NO', None]
    while curr < d:
        for i in range(len(answer)-1, -1, -1):
            if answer[i] > 1:
                break
        answer[i]-=1
        if i==len(answer)-1:
            answer.append(1)
        else:
            answer[i+1]+=1
        curr+=1
    assert sum([i*answer[i] for i in range(len(answer))])==d
    depths = [[] for i in range(len(answer))]
    depth1 = [None for i in range(n+1)]
    children = [0 for i in range(n+1)]
    final_answer = [None for i in range(n-1)]
    I = 0
    p = 1
    depth1[p] = 0
    for i in range(1, n+1):
        if len(depths[I])==answer[I]:
            I+=1
        while children[p]==2 or depth1[p] < I-1:
            p+=1
        if i > 1:
            final_answer[i-2] = p
            children[p]+=1
        depths[I].append(i)
        depth1[i] = I
  #  print(answer)
  # print(depths)
   # print(depth1)
    #print(final_answer)
    return ['YES', final_answer]

t = int(input())
for i in range(t):
    n, d = [int(x) for x in input().split()]
    a1, a2 = process(n, d)
    print(a1)
    if a1=='YES':
        sys.stdout.write(' '.join(map(str, a2))+'\n')
    