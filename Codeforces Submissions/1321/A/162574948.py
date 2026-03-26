n = int(input())
r = list(map(int,input().split()))
b = list(map(int,input().split()))
rt = 0
bt = 0
for i in range(n):
    if r[i]!=b[i]:
        if r[i]>b[i]:
            rt+=1
        else:
            bt+=1
if rt>bt:
    print('1')
else:
    if rt==0:
        print('-1')
    else:
        if bt%rt==0:
            print(bt//rt + 1)
        else:
            print((bt+(rt-bt%rt))//rt)

