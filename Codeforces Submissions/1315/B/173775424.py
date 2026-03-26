def feasible(mid,a,b,s,p):
    changes = 0
    cost = 0

    if mid<len(s)-1:
        if s[mid]=="A":
            cost+=a
        else:
            cost+=b

    for i in range(mid+1,len(s)-1):
        if i>0 and s[i]!=s[i-1]:
            changes+=1
            if s[i]=='A':
                cost+=a
            else:
                cost+=b
        if cost>p:
            return False
    if cost>p:
        return False
    return True
        
        





for _ in range(int(input())):
    a,b,p = map(int,input().split())
    s = input()

    left = 0
    right = len(s)-1
    ans = len(s)-1

    while left<=right:
        mid = left + (right- left)//2

        if feasible(mid,a,b,s,p):
            ans = mid
            right = mid-1
        else:
            left = mid+1

    print(ans+1)