for _ in range(int(input())):
    n=int(input())
    s=input()
    k=1
    res=s
    for j in range(1,n+1):
        mov=n-j+1
        t=s[:j-1]
        final=s[j-1:]
        if mov%2==0:
            final+=t
        else:
            final=final+t[::-1]
        if res>final:
            k=j
            res=final
    print(res)
    print(k)    