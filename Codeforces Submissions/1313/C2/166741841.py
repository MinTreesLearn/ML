from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

def answer():

    left , s = [-1 for i in range(n)] , []
    for i in range(n - 1 , -1 , -1):

        while(len(s) and a[s[-1]] >= a[i]):
            left[s.pop()] = i

        s.append(i)


    right , s = [n for i in range(n)] , []
    for i in range(n):

        while(len(s) and a[s[-1]] >= a[i]):
            right[s.pop()] = i

        s.append(i)

    
    sumval = [0 for i in range(n + 1)]
    for i in range(n):
        sumval[i + 1] = sumval[i] + a[i]

    prefix = [0 for i in range(n + 1)]
    for i in range(n):
        sval = sumval[i] - sumval[left[i] + 1]
        prefix[i + 1] = prefix[left[i] + 1] + sval - (i - left[i] - 1) * a[i]


    suffix = [0 for i in range(n + 1)]
    for i in range(n - 1 , -1 , -1):
        sval = sumval[right[i]] - sumval[i + 1]
        suffix[i] = suffix[right[i]] + sval - (right[i] - i - 1) * a[i]

    best = float('inf')
    for i in range(n):
        value = prefix[i + 1] + suffix[i]

        if(best > value):
            best = value
            peak = i
            

    for i in range(peak - 1 , -1 , -1):
        if(a[i] > a[i + 1]):
            a[i] = a[i + 1]

    for i in range(peak + 1 , n):
        if(a[i] > a[i - 1]):
            a[i] = a[i - 1]


    return a
        

for T in range(1):

    n = int(input())
    a = inp()

    print(*answer())
