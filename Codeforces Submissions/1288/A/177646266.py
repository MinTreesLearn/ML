t = int(input())
for i in range(t):
    n,d = map(int,input().split())
    if d<=n:
        print("YES")
    else:
        x = (n-1)/2
        if d>((n-x)*(x+1)):
          print('NO')
        else:
          print('YES')