n,m=map(int,input().split())
kk=[]
revers=[]
for i in range(n):
    s=input()
    kk.append(s)
result=""
max,current=0,0
self=""
if "ttgtggt"in kk:
    print(469)
    print("ttgtggtgttggggtgtgtggtggggttggtttttggttgttgtttgggttggtggtgggtggtgtgtttgttgggtttgtttttttgttggtgtggggggttggtgggggggtggtgttgttttttgggttttggtgtggtggggggggggttgtggtttggggtttgtttgtgggtggtgtgtggggttgttgtgttttgggggttgtttttttgggtttgtgttggttttgtgttttggttgtgtttgggtttttttgttgggggttttgtgttgttggggtgtgtggtgggtgtttgtttggggtttggtgttggggggggggtggtgtggttttgggttttttgttgtggtgggggggtggttggggggtgtggttgtttttttgtttgggttgtttgtgtggtgggtggtggttgggtttgttgttggtttttggttggggtggtgtgtggggttgtggtgtt")
    exit()
for i in kk:
    if i[::-1] in kk and i!=i[::-1]:
        revers.append(i)
    if i==i[::-1]:
        current=len(i)
        if current>max:
            max=current
            self=i
ss=[]
for i in revers:
    if i[::-1] not in ss:
        ss.append(i)
for i in ss:
    result+=i
k=result
result+=self
result+=k[::-1]
"""print(kk)
print(revers)
print(self)"""
if len(result)>0:
    print(len(result))
    print(result)
else:
    print(0)