def predictFeature(a,b):
    if a==b:
        return a
    else:
        if 'S' in (a,b):
            pass
        else:
            return 'S'
        if 'T' in (a,b):
            pass
        else:
            return 'T'

        return 'E'

def hyperSet(n,k,l):
    d = {}
    for x in l:
        if x not in d:
            d[x]=1
        else:
            d[x]+=1

    ans = 0
    for i in range(n):
        for j in range(n):
            if i!=j:
                w = ''
                for x in range(k):
                    w += predictFeature(l[i][x],l[j][x])
                # print(w)
                if w in d:
                    c=0
                    if w==l[i]:
                        c+=1
                    if w==l[j]:
                        c+=1
                    ans += d[w]-c

    return ans//6


n,k = map(int,input().split())
l = []
for _ in range(n):
    l.append(input())
print(hyperSet(n,k,l))
