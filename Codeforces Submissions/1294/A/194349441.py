for _ in range(int(input())):
    a,b,c,d = map(int,input().split())
    s = a+b+c+d
    s1 = max(a, b,c) <= s//3
    if( s%3 ==0 and s1):
        print("YES")
    else:
        print("NO")