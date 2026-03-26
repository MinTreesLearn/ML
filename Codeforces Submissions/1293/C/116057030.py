n,m = map(int,input().split())
t = [0]*n
o = [0]*n
b = 0
for i in range(m):
    w,v = map(int,input().split())
    v-=1
    if(w == 1):
        o[v] = 1-o[v]
        if (o[v] == 1):
            if t[v] == 1: b += 1
            if v > 0 and t[v - 1] == 1: b += 1
            if v < n - 1 and t[v + 1] == 1: b += 1
        if (o[v] == 0):
            if t[v] == 1: b -= 1
            if v > 0 and t[v - 1] == 1: b -= 1
            if v < n - 1 and t[v + 1] == 1: b -= 1
    else:
        t[v] =1-t[v]
        if (t[v] == 1):
            if o[v] == 1:b += 1
            if v > 0 and o[v - 1] == 1: b+=1
            if v < n - 1 and o[v + 1] == 1: b+=1
        if (t[v] == 0):
            if o[v] == 1: b -= 1
            if v > 0 and o[v - 1] == 1: b -= 1
            if v < n - 1 and o[v + 1] == 1: b -= 1
    if b==0:
        print("Yes")
    else:
        print("No")

