from collections import defaultdict as dc
n=int(input())
a,b=list(input()),list(input())
frqa=dc(lambda:list())
frqb=dc(lambda:list())
for i in range(n):frqa[a[i]].append(i)
for i in range(n):frqb[b[i]].append(i)
i=96
ans=list()
#print(ord('?'))=63
while i<=122:
    i+=1
    c=chr(i)
    if c in frqa and c in frqb:
        while len(frqa[c]) and len(frqb[c]):ans.append((frqa[c].pop()+1,frqb[c].pop()+1))
        if len(frqa[c]):
            while len(frqa[c]) and len(frqb['?']):ans.append((frqa[c].pop()+1,frqb['?'].pop()+1))
        elif len(frqb[c]):
            while len(frqa['?']) and len(frqb[c]):ans.append((frqa['?'].pop()+1,frqb[c].pop()+1))
    elif c in frqa:
        while len(frqa[c]) and len(frqb['?']):ans.append((frqa[c].pop()+1,frqb['?'].pop()+1))
    elif c in frqb:
        while len(frqa['?']) and len(frqb[c]):ans.append((frqa['?'].pop()+1,frqb[c].pop()+1))
while len(frqa['?']) and len(frqb['?']):ans.append((frqa['?'].pop()+1,frqb['?'].pop()+1))
print(len(ans))
for i in ans:print(i[0],i[1])