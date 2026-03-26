a=int(input())
for i in range(a):
    n=int(input())
    a1=input().split()
    a2=input().split()
    a1=[int(f) for f in a1]
    a2=[int(f) for f in a2]
    a1.sort()
    a2.sort()
    for j in range(n):
        print(a1[j],end=" ")
    print()
    for j in range(n):
        print(a2[j],end=" ")
    print()    
        
    