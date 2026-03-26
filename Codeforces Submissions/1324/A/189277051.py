for i in range(int(input())):
    h = int(input())
    a = sum(list(map(lambda x: int(x)%2, input().split())))
    if(a==0 or a==h):
        print("YES")
    else:
        print("NO")