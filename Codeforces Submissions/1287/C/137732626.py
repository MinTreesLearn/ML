def process(A):
    n = len(A)
    if n % 2==0:
        odd = n//2
        even = n//2
    else:
        odd = n//2+1
        even = n//2
    for x in A:
        if x > 0:
            if x % 2==0:
                even-=1
            else:
                odd-=1
    pairs = {'o': [], 'oo': [], 'oe': [], 'e': [], 'ee': []}
    curr = 0
    last = None
    answer = 0
    for i in range(n):
        if A[i]==0:
            curr+=1
        else:
            if A[i] % 2==0:
                if last is None:
                    type1 = 'e'
                elif last % 2==0:
                    type1 = 'ee'
                else:
                    type1 = 'oe'
            else:
                if last is None:
                    type1 = 'o'
                elif last % 2==1:
                    type1 = 'oo'
                else:
                    type1 = 'oe'
            if curr != 0:
                pairs[type1].append(curr)
            last = A[i]
            if i > 0 and A[i-1] != 0 and (A[i-1] % 2) != (A[i] % 2):
                answer+=1
            curr = 0
    if curr != 0:
        if last is None and n > 1:
            return 1
        elif last is None:
            return 0
        if last % 2==0:
            type1 = 'e'
        else:
            type1 = 'o'
        pairs[type1].append(curr)
    for x in pairs:
        pairs[x] = sorted(pairs[x], reverse=True)
    while True:
        if len(pairs['ee']) > 0 and pairs['ee'][-1] <= even:
            x = pairs['ee'].pop()
            even-=x 
        else:
            break
    while True:
        if len(pairs['e']) > 0 and pairs['e'][-1] <= even:
            x = pairs['e'].pop()
            even-=x 
        else:
            break
    while True:
        if len(pairs['oo']) > 0 and pairs['oo'][-1] <= odd:
            x = pairs['oo'].pop()
            odd-=x
        else:
            break
    while True:
        if len(pairs['o']) > 0 and pairs['o'][-1] <= odd:
            x = pairs['o'].pop()
            odd-=x
        else:
            break
    return answer+2*len(pairs['ee'])+len(pairs['oe'])+2*len(pairs['oo'])+len(pairs['o'])+len(pairs['e'])

n = int(input())
A = [int(x) for x in input().split()]
print(process(A))
                
    