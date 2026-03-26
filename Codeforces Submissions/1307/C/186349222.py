def update(s,aa,ans):
    for r in range(26):
        if r!=s:
            ans[s][r]+=aa[r]
        else:
            ans[s][r]+=(aa[r]-1)
    return
a=input()
aa=[0]*26
fans=0
ans=[[0]*26 for i in range(26)]
for i in a:
    aa[ord(i)-ord('a')]+=1
    update((ord(i)-ord('a')),aa,ans)
for i in range(26):
    for j in range(26):
        fans=max(fans,ans[i][j])
    fans=max(fans,aa[i])
print(fans)
    