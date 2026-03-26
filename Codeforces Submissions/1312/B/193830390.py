t= int(input())
for i in range(t):
    n= int(input())
    l=[int(x) for x in input().split()]
    l.sort()
    l.reverse()
    print(*l)