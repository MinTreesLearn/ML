n,m = tuple(map(int,input().split()))
l=[]
for i in range(n):
    s = input()
    l.append(s)

ans = []
flag = True
for i in range(len(l)):
    if (l[i]=="#"):
        continue
    try:
        x = l.index(l[i][::-1],i+1)
    except:
        x=-1
    if (x==-1):
        if (flag):
            if(l[i]==l[i][::-1]):
                flag=False
                ans.insert(len(ans)//2,l[i])
    else:
        ans.append(l[x])
        ans.insert(0,l[i])
        l[x] = "#"
length = 0
for i in ans:
    length+=len(i)
print(length)
for i in ans:
    print(i,end='')

    

