for _ in range(int(input())):
    n= int(input())
    l=list(map(int,input().split()))
    imp=False
    p=False
    s=0
    for i in l:
        s+=i
        if i%2==1 and not imp:imp=True
        if i%2==0 and not p:p=True
    if s%2==1 or (imp and p):print("YES")
    else:print("NO")
