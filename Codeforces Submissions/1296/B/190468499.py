t=int(input())
for r in range (t):
    n=int(input())
    spends=n
    while n>=10:
        spends+=n//10
        n=n//10+n%10
    print(spends)