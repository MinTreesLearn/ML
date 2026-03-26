n=int(input())
l=input()
r=input()
ldic={}
rdic={}
for i in range(n):
    if l[i] in ldic:
        ldic[l[i]].append(i)
    else:
        ldic[i]=[i]
for i in range(n):
    if r[i] in rdic:
        rdic[r[i]].append(i)
    else:
        rdic[r[i]]=[i]
li=[]
for i in range(n):
    li.append([l[i],i])
li.sort()
nli=[]
c=0
for i in range(n):
    if li[i][0]=="?":
        c+=1
    else:
        break
nli=li[c:]+li[:c]
# print(nli)
# print(rdic)
ans=[]
visb=[0]*n
for i in range(n):
    if nli[i][0]!="?":
        if nli[i][0] in rdic and len(rdic[nli[i][0]])>0:
            num=rdic[nli[i][0]][-1]
            rdic[nli[i][0]].pop(-1)
            ans.append([nli[i][1]+1,num+1])
        else:
            if "?" in rdic and len(rdic["?"])>0:
                num=rdic["?"][-1]
                rdic["?"].pop(-1)
                ans.append([nli[i][1]+1,num+1])
    else:
        z=0
        for j in rdic:
            if j!="?" and len(rdic[j])>0:
                num=rdic[j][-1]
                rdic[j].pop(-1)
                ans.append([nli[i][1]+1,num+1])
                z=1
                break
        if z==0:
            for j in rdic:
                if j=="?" and len(rdic[j])>0:
                    num=rdic[j][-1]
                    rdic[j].pop(-1)
                    ans.append([nli[i][1]+1,num+1])
                    z=1
                    break
print(len(ans))
for i in ans:
    print(*i)
