n = int(input())
for i in range(n):
    p,q = [int(i) for i in input().split()]
    if p==q:
        print(0)
    elif p<q:
        diff = q-p
        if diff%2==0:
            print(2)
        else:
            print(1)
    elif p>q:
        diff = p-q
        if diff%2==0:
            print(1)
        else:
            print(2)
        