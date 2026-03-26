n,s1,s2=int(input()), input(), input()
left=dict()
right=dict()
sol=[]
for i in range(n):
    arr1=left.get(s1[i], [])
    arr1.append(i+1)
    left[s1[i]]=arr1
    
    arr2=right.get(s2[i], [])
    arr2.append(i+1)
    right[s2[i]]=arr2

leftunmatched=[]
rightunmatched=[]
for c in set(left.keys()).union(right.keys()):
    if c != "?":
        cleft=left.get(c,[])
        cright=right.get(c,[])
        match=min(len(cleft), len(cright))
        for i in range(match):
            sol.append([cleft[i], cright[i]])
        leftunmatched.extend(cleft[match:])
        rightunmatched.extend(cright[match:])

lsz=min(len(leftunmatched), len(right.get("?",[]) ) )
for i in range(lsz):
    sol.append([leftunmatched[i], right["?"][i]])

rsz=min(len(rightunmatched), len(left.get("?",[]) ) )
for i in range(rsz):
    sol.append([left["?"][i], rightunmatched[i]])

pairs = min(len(left.get("?",[]))-lsz, len(right.get("?",[]))-rsz)
for i in range(pairs):
    sol.append([left["?"][lsz+i],right["?"][rsz+i]])
    
print(len(sol))
for a in sol:
    print(a[0], a[1])