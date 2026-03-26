for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    ans="NO"
    for i in range(n-2):
        if a[i] in a[i+2:]: ans="YES"; break
    print(ans)