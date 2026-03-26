n=int(input())
for i in range(1, n+1):
    a=input()
    b=a.find('1')
    c=a.rfind('1')
    if b!=-1 and c!=-1:
        p=a[b+1:c]
        k=p.count('0')
        print(k)
    else:
        print(0)