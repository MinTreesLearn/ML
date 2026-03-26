import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP1/output.txt",'w')
# sys.stdin=open("CP1/input.txt",'r')

# m=pow(10,9)+7
n,m,k=map(int,input().split())
if k>(4*m*n-2*n-2*m):
    print("NO")
else:
    k1=k
    print("YES")
    s=''
    c=0
    if m>=n:
        flag=0
        d=min(k,m-1)
        if d!=0:
            s+=str(d)+' R'+'\n'
            k-=d
            c+=1
        while k:
            # print(k)
            if c==2*n+n-1:
                c+=1
                s+=str(k)+' U\n'
                break
            if flag%3==0:
                d=min(k,m-1)
                s+=str(d)+' L'+'\n'
                k-=d
                flag+=1
            elif flag%3==1:
                s+='1 D\n'
                flag+=1
                k-=1
            else:
                d=min(k,(m-1)*3)
                if d==3*(m-1):
                    s+=str(m-1)+' RUD'+'\n'
                else:
                    if k>=3:
                        s+=str(k//3)+' RUD'+'\n'
                    else:
                        c-=1
                    if d%3==1:
                        s+='1 R\n'
                        c+=1
                    elif d%3==2:
                        s+='1 RU\n'
                        c+=1

                k-=d
                flag+=1
            c+=1
    else:
        flag=0
        d=min(k,n-1)
        if d!=0:
            s+=str(d)+' D'+'\n'
            k-=d
            c+=1
        while k:
            if c==2*m+m-1:
                c+=1
                s+=str(k)+' L\n'
                break
            if flag%3==0:
                d=min(k,n-1)
                s+=str(d)+' U'+'\n'
                k-=d
                flag+=1
            elif flag%3==1:
                s+='1 R\n'
                flag+=1
                k-=1
            else:
                d=min(k,(n-1)*3)
                if d==3*(n-1):
                    s+=str(n-1)+' DLR'+'\n'
                else:
                    if k>=3:
                        s+=str(k//3)+' DLR'+'\n'
                    else:
                        c-=1
                    if d%3==1:
                        s+='1 D\n'
                        c+=1
                    elif d%3==2:
                        s+='1 DL\n'
                        c+=1
                k-=d
                flag+=1
            c+=1
    print(c)
    print(s[:-1])