def process(A, n):
    q = len(A)
    answer = []
    d = {}
    adj_count = 0
    for a, b in A:
        if b not in d:
            d[b] = set([])
        if a in d[b]:
            d[b].remove(a)
            for b2 in [b-1, b, b+1]:
                if b2 in d and (3-a) in d[b2]:
                    adj_count-=1
        else:
            d[b].add(a)
            for b2 in [b-1, b, b+1]:
                if b2 in d and (3-a) in d[b2]:
                    adj_count+=1
        if adj_count==0:
            answer.append('YES')
        else:
            answer.append('NO')
    return answer
            
#0 0 0 X 0 
#0 X 0 0 0
n, q = [int(x) for x in input().split()]
A = []
for i in range(q):
    a, b = [int(x) for x in input().split()]
    A.append([a, b])
for x in process(A, n):
    print(x)