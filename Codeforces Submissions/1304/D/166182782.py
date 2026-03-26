
for _ in range(int(input())):
    p=[el for el in input().split()]
    n=int(p[0])
    s=p[1]
    ans=[0]*n
    num=n
    last=0
    for i in range(n):
        if i==n-1 or s[i]==">":
            j=i
            while j>=last :
                ans[j]=num
                num-=1
                j-=1
            last=i+1
            
    print(*ans)
    ans=[0]*(n)
    num=1
    last=0
    for i in range(n):
        if i==n-1 or s[i]=="<":
            j=i
            while j>=last :
                ans[j]=num
                num+=1
                j-=1
            last=i+1
    print(*ans)
    