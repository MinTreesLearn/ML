import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
sa=[0]+[a[i] for i in range(n)]
for i in range(1,n+1):
    sa[i]+=sa[i-1]
dd={}
for i in range(n+1):
    for j in range(i+1,n+1):
        if sa[j]-sa[i] in dd:
            dd[sa[j]-sa[i]].append([i+1,j])
        else:
            dd[sa[j]-sa[i]]=[[i+1,j]]
ans=[]
for v in dd.keys():
    arr=dd[v]
    arr.sort(key=lambda x:x[1])
    zantei=[]
    for i in range(len(arr)):
        if len(zantei)==0:
            zantei.append(arr[i])
        else:
            if zantei[-1][1]<arr[i][0]:
                zantei.append(arr[i])
    if len(zantei)>len(ans):
        ans=zantei
print(len(ans))
for l,r in ans:
    print(l,r)