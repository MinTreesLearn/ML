s=input()
m=[]
for i in range(len(s)+1):
    m.append([])
    for j in range(26):
        m[-1].append(0)
for i in range(len(s)):
    for j in range(26):
        if j==ord(s[i])-97:
            m[i+1][j]=m[i][j]+1
        else:
            m[i+1][j]=m[i][j]
q=int(input())
for _ in range(q):
    l,r=map(int,input().split())
    if l==r:
        print('Yes')
        continue
    count=0
    for i in range(26):
        if m[l-1][i]!=m[r][i]:
            count+=1
    if count==1:
        print('No')
    else:
        if count>=3:
            print('Yes')
        else:
            if s[l-1]==s[r-1]:
                print('No')
            else:
                print('Yes')