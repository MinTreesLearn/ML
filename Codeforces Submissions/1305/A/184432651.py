a=int(input())
for i in range(a):
    n=int(input())
    a1=list(map(int, input().split()))
    a2=list(map(int, input().split()))
    a1.sort()
    a2.sort()
    for j in range(n):
        print(a1[j],end=" ")
    print()
    for j in range(n):
        print(a2[j],end=" ")
    print()    
        
    