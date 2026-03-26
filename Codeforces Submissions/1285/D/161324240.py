from sys import stdin
input = stdin.readline



def solve(root , bit):

    if(trie[root] == [-1 , -1]):return 0

    if(trie[root][0] != -1 and trie[root][1] == -1):
        ans = solve(trie[root][0] , bit - 1)
    elif(trie[root][0] == -1 and trie[root][1] != -1):
        ans = solve(trie[root][1] , bit - 1)
    else:
        ans = min(solve(trie[root][0], bit - 1) , solve(trie[root][1] , bit - 1))
        ans += (1 << bit)

    return ans


def answer():

    global trie

    d = dict()

    trie = [[-1 , -1] for i in range(30)]
    freespace = 1
    for i in range(n):

        if(d.get(a[i] , False)):continue
        
        d[a[i]] = True

        root = 0
        for bit in range(29 , -1 , -1):
            
            v = (a[i] >> bit & 1)

            if(trie[root][v] == -1):
                trie[root][v] = freespace
                trie.append([-1 , -1])
                freespace += 1

            root = trie[root][v]

    ans = solve(0 , 29)

    return ans


for T in range(1):

    n = int(input())
    a = list(map(int,input().split()))

    print(answer())
