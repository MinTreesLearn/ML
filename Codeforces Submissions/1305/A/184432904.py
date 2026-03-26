a=int(input())
for i in range(a):
    n=int(input())
    a1=list(map(int, input().split()))
    a2=list(map(int, input().split()))
    a1.sort()
    a2.sort()
    print(*a1)
    print(*a2)
        
    