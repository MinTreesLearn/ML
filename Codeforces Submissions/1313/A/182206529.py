for _ in range(int(input())):
    a,b,c=map(int,input().split())
    cnt=0
    if a:
        cnt+=1
        a-=1
    if b:
        cnt+=1
        b-=1
    if c:
        cnt+=1
        c-=1
    
    if a==1 and b==1 and c>1:
        cnt+=2
        a-=1
        b-=1
        c-=2
    elif a==1 and b>1 and c==1:
        cnt+=2
        a-=1
        b-=2
        c-=1
    elif a>1 and b==1 and c==1:
        cnt+=2
        a-=2
        b-=1
        c-=1
    else:
        if a>0 and b>0:
            cnt+=1
            a-=1
            b-=1
        if b>0 and c>0:
            cnt+=1
            b-=1
            c-=1
        if a>0 and c>0:
            cnt+=1
            a-=1
            c-=1
    if a>0 and b>0 and c>0:
        cnt+=1
    print(cnt)