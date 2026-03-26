import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
n=int(input())
a=list(map(int,input().split()))
stack=[]
for aa in a:
    stack.append([aa,1])
    while len(stack)>1 and stack[-1][0]/stack[-1][1]<stack[-2][0]/stack[-2][1]:
        stack[-2]=[stack[-2][0]+stack[-1][0],stack[-2][1]+stack[-1][1]]
        stack.pop()
b=[]
for block,l in stack:
    b.extend([str(block/l)]*l)
print("\n".join(b))