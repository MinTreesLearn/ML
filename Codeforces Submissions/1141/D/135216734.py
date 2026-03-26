n=int(input()) 
left=input() 
right=input() 

leftlist=[[] for _ in range(27)]  

for i in range(n):
    if left[i]!='?':
        leftlist[ord(left[i])-ord('a')].append(i)
    else:
        leftlist[26].append(i) 
res=[] 
temp=[]
for i in range(n):
    if right[i]=='?':
        temp.append(i) 
    else:
        x=ord(right[i])-ord('a')
        if len(leftlist[x])!=0:
            res.append([leftlist[x].pop()+1,i+1])
        elif len(leftlist[26])!=0:
            res.append([leftlist[26].pop()+1,i+1])
for l in leftlist:
    while temp and l:
        res.append([l.pop()+1,temp.pop()+1])
        
print(len(res))
for r in res:
    print(*r)