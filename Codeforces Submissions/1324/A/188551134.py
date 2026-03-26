for run in range(int(input())):
    n=int(input())
    lst=list(map(int,input().split()))
    if lst[0]%2==0:
        odd=False
    else:
        odd=True
    for i in range(1,n):
        if odd and lst[i]%2!=1:
            odd='x'
            print('NO')
            break
        if odd==False and lst[i]%2!=0:
            odd='x'
            print('NO')
            break
    if odd!='x':
        print('YES')
