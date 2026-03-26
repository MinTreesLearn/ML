a=int(input())
for x in range(a):
    b=input()
    if b.count('1')==0 or b.count('0')==0 or b.count('1')==1:
        print(0)
    else:
        m=b.index('1')
        s=len(b)-1
        while b[s]!='1':
            s-=1
        print(b[m:s+1].count('0'))