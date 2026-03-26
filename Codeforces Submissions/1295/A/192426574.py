t=int(input())
for i in range(t):
    n=int(input())
    if n%2!=0:
        s='7'
        for j in range((n-3)//2):
            s+="1"
        print(s)
    else:
        s=""
        for j in range(n//2):
            s+='1'
        print(s)