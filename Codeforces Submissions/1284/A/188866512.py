n,m = list(map(int,input().split()))
a = input().split()
b = input().split()
for i in range(int(input())):
    c = int(input())
    print(a[(c-1) % n]+b[(c-1) % m])