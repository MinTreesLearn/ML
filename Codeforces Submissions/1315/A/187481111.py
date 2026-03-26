n = int(input())
for i in range(n):
    a,b,x,y = map(int,input().split())
    print(max(b*(a-1-x),b*(x),a*(b-1-y),a*y))