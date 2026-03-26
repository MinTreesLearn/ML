import sys
input=sys.stdin.readline
s=input().rstrip('\n')
l=len(s)
ref=[[0]*26]
ref1=[0]*26
for i in range(l):
    #print(ord(s[i]))
    ref1[ord(s[i])-97]+=1
    ref.append(ref1.copy())
#@print(ref)
q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    if(l==r or s[l-1]!=s[r-1]):
        print('Yes')
        continue
    p=0
    f=[ref[r][k]-ref[l-1][k] for k in range(26)]
    for i in f:
        if(i>0):
            p+=1
    if(p>=3):
        print('Yes')
    else:
        print('No')
