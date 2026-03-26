from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

def answer():


    ans = []

    j = n - 1
    for i in range(n):
        if(a[i] == '('):

            while(j > i and a[j] == '('):
                j -= 1

            if(j == i):break

            ans.append(i + 1)
            ans.append(j + 1)
            j -= 1

        if(i == j):break

    if(len(ans) == 0):
        print(0)
        return

    ans.sort()
    print(1)
    print(len(ans))
    print(*ans)
                

for T in range(1):

    a = input().strip()
    n = len(a)
    
    answer()
    
