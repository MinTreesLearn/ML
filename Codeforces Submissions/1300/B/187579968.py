t = int(input())
while t>0:
    n = int(input())
    l = [int(a) for a in input().split(" ",2*n-1)]
    l.sort()
    print(l[n]-l[n-1])
    t-=1
    