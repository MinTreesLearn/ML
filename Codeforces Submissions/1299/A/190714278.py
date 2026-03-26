def rl():
    return list(map(int,input().split()))
def ri():
    return int(input())
def rs():
    return input()
def rm():
    return map(int,input().split())
def solve():
    n=ri()
    a=rl()
    nm=[0 for i in range(30)]
    for i in range(n):
        s=bin(a[i])[-1:1:-1]
        for j in range(len(s)):
            if s[j]=='1': nm[j]+=1
    r=-1
    id=-1
    for i in range(n):
        s=bin(a[i])[-1:1:-1]
        c=0
        for j in range(len(s)):
            if s[j]=='1' and nm[j]==1:
                c+=2**j
        if c>r: 
            r=c
            id=i
    return [a[id]]+a[:id]+a[id+1:]
print(*solve())

