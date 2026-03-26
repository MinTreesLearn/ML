t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    if(sum(l)%2==1):
        print("YES")
        continue
    else:
        e = 0
        o = 0
        j = 0
        while((e==0 or o==0) and j<n):
            if(l[j]%2==0):
                e = 1
            else:
                o = 1
            j = j + 1
        if(e==o):
            print("YES")
        else:
            print("NO")