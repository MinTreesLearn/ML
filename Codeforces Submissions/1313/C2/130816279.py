# ЛАсСД 6 - Небоскребы

def up_east(aaa,n):
    st=[0]
    bbb=[0]*(n+2)
    xxx=[0]
    for i in range (1,n+1):
        a=aaa[i]
        if a>=aaa[st[-1]] :
            bbb[i]=bbb[i-1]+a
        else:
            while a<aaa[st[-1]] : #st всегда не пуст!!!
                j=st.pop()
            j=st[-1]
            bbb[i]=bbb[j]+a*(i-j)
        st.append(i)
        if a>=aaa[i-1] and a>aaa[i+1] :
            xxx.append(i)
    st.clear()
    return bbb,xxx

def down_east(aaa,n):
    st=[n+1]
    bbb=[0]*(n+2)
    for i in range (n,0,-1):
        a=aaa[i]
        b=aaa[st[-1]]
        if a>=b :
            bbb[i]=bbb[i+1]+a
        else:
            while a<aaa[st[-1]] : #st всегда не пуст!!!
                j=st.pop()
            j=st[-1]
            bbb[i]=bbb[j]+a*(j-i)
        st.append(i)
    st.clear()
    return bbb



N=int(input())
AAA=list(map(int,('0 '+input()).split()))
AAA.append(0)
UpE,XXX=up_east(AAA,N)
DwE=down_east(AAA,N)
rb=0
for x in XXX :
    r=UpE[x]+DwE[x]-AAA[x]
    if r>rb:
        rb=r
        y=x
        
for i in range(y-1,0,-1):
    AAA[i]=min(AAA[i],AAA[i+1])
for j in range(y+1,N+1,):
    AAA[j]=min(AAA[j-1],AAA[j])
for a in AAA[1:-1]:
    print(a,end=' ')



 
