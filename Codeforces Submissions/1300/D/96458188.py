n=int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))
if n%2==1:
    print('NO')

else:
    #print(n//2,'this is it')
    a=arr[:n//2]
    b=arr[n//2:]
    flag=True
    for i in range(1,n//2):
        #print(i,'i')
        if (a[i][0]-a[i-1][0]!=b[i-1][0]-b[i][0]) or (a[i][1]-a[i-1][1]!=b[i-1][1]-b[i][1]):
            flag=False
            break
    if flag:
        print('YES')
    else:
        print('NO')
