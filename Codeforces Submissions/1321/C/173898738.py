n=int(input())
s=input()
for _ in range(len(s)):
    mx=0
    ind=-1 
    for i in range(len(s)):
        a=-1
        b=-1
        if i>0:
            if ord(s[i-1])==ord(s[i])-1:
                a=i 
        if i+1<len(s):
            if ord(s[i+1])==ord(s[i])-1:
                b=i
        if a==i or b==i:
            if ord(s[i])>mx:
                mx=ord(s[i])
                ind=i 
    if ind==-1:
        break 
    else:
        s=s[:ind]+s[ind+1:]
    
print(n-len(s))