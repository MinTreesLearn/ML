for _ in range(int(input())):
    n,d=map(int,input().split())
    l=list(map(int,input().split()))
    m_=l[0]
    w=1
    i=1
    while d>0:
        if i<n:
            if l[i]>0:
                if d>=(l[i]*w):
                    m_=m_+l[i]
                    d=d-(l[i]*w)
                    l[i]=0
                    i+=1
                    w+=1
                    #print(d)
                else:
                    q=d//w
                    m_=m_+q
                    d=0
            else:
                i+=1
                w+=1

        else:
            break

    print(m_)






