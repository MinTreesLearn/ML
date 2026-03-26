n=int(input());x=[0]
for i in input().split():x+=x[-1]+int(i),
m=min(x)
print(*([-1],[i-m+1 for i in x])[set(x)==set(range(m,m+n))])