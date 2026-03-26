x=int(input())
a=list(input())
b=list(input())
a1=[[] for i in range(26)]
q=[]
b1=[[] for i in range(26)]
q1=[]
ans=[]
for i in range(len(a)):
    if(a[i]=='?'):
        q.append(i)
    else:
        a1[ord(a[i])-ord('a')].append(i)
for i in range(len(b)):
    if(b[i]=='?'):
        q1.append(i)
    else:
        b1[ord(b[i])-ord('a')].append(i)
for i in range(26):
    if(a1[i]!=[]) and (b1[i]!=[]):
        p=min([len(a1[i]),len(b1[i])])
        for j in range(p):
            ans.append([a1[i][len(a1[i])-1],b1[i][len(b1[i])-1]])
            a1[i].pop(len(a1[i])-1)
            b1[i].pop(len(b1[i])-1)
for i in range(26):
    if(b1[i]!=[]):
        p=min([len(q),len(b1[i])])
        for j in range(p):
            ans.append([q[len(q)-1],b1[i][len(b1[i])-1]])
            q.pop(len(q)-1)
            b1[i].pop(len(b1[i])-1)
    if(a1[i]!=[]):
        p=min([len(q1),len(a1[i])])
        for j in range(p):
            ans.append([a1[i][len(a1[i])-1],q1[len(q1)-1]])
            q1.pop(len(q1)-1)
            a1[i].pop(len(a1[i])-1)
p=min(len(q),len(q1))
for i in range(p):
    ans.append([q[len(q)-1],q1[len(q1)-1]])
    q.pop(len(q)-1)
    q1.pop(len(q1)-1)
print(len(ans))
for i in range(len(ans)):
    print(ans[i][0]+1,ans[i][1]+1)