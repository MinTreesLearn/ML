for _ in range(int(input())):
    n = int(input())
    s = input()
    odd = []
    for i in range(n):
        if(int(s[i])%2 !=0):
            odd.append(s[i])
    
    if(len(odd)>=2):    
        odd = odd[-2:]
        r = "".join(odd)
        print(r)
    else:
        print(-1)