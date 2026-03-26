n=int(input())
s=list(input())
for j in range(122,96,-1):
    l=0
    while l!=len(s):
        if ord(s[l])==j:
            if (l!=0 and ord(s[l-1])==j-1) or (l!=len(s)-1 and ord(s[l+1])==j-1):
                s.pop(l)
                l=-1
        l+=1
print(n-len(s))                                         
                
