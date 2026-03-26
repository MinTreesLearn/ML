from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

"""
sud make 1 0 bits
"""

def answer():

    count = [0 for i in range(30)]
    index = [-1 for i in range(30)]
    for i in range(n):
        for j in range(30):

            if(a[i] >> j & 1):
                count[j] += 1
                index[j] = i


    ans , done = [] , set()
    for i in range(29 , -1 , -1):
        if(count[i] != 1):continue
        if(index[i] in done):continue

        ans.append(a[index[i]])
        done.add(index[i])


    for i in range(n):
        if(i in done):continue

        ans.append(a[i])

    return ans
            

 
for T in range(1):

    n = int(input())
    a = inp()

    print(*answer())
