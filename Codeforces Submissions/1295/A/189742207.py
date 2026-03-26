for run in range(int(input())):
    n=int(input())
    s=''
    if n%2==1:
        s+='7'
        n-=3
    while n>0:
        s+='1'
        n-=2
    print(s)