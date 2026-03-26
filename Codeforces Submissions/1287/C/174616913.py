import sys
input = sys.stdin.readline
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = stack.append(f(*args, **kwargs))
            while True:
                try:
                    to = stack.append(stack[-1].send(to))
                except StopIteration as e:
                    stack.pop()
                    to = e.value
                    if not stack:
                        break
            return to
 
    return wrappedfunc
 
@bootstrap
def go(ind,prev,ce,co):

    if (ind==n):
        return 0 


    # prev ==0 --> prev element is even 
    # prev ==1 --> prev element is odd 

    if (dp[prev][co][ce][ind]!=-1):
        return dp[prev][co][ce][ind]

    c1 = 10**9 
    c2 = 10**9 
    if (a[ind]!=0):
        if (a[ind]%2==0):
            if (prev==0):
                c1 = (yield go(ind+1,prev,ce,co)) 
            else:
                c1 = 1 + (yield go(ind+1,prev^1,ce,co)) 
        else:
            if (prev==0):
                c1 = 1 + (yield go(ind+1,prev^1,ce,co)) 
            else:
                c1 = (yield go(ind+1,prev,ce,co)) 

    else:
        if (prev==0):
            if (ce>0):
                c1 = (yield go(ind+1,prev,ce-1,co)) 
            if (co>0):
                c2 = 1 + (yield go(ind+1,prev^1,ce,co-1)) 
        else:
            if (ce>0):
                c1 = 1 + (yield go(ind+1,prev^1,ce-1,co)) 
            if (co>0):
                c2 = (yield go(ind+1,prev,ce,co-1)) 


    ans = min(c1,c2)
    dp[prev][co][ce][ind] = ans 

    return min(c1,c2)




 


n = int(input()) 
a = list(map(int,input().split())) 
if (n%2==0):
    even = n//2 
    odd = n//2  

else:
    even = n//2 
    odd = n//2 + 1 

for i in a:
    if (i==0):
        continue
    if (i%2):
        odd-=1 
    else:
        even-=1 

dp = [ ] 
for i in range(2):
    x = [ ] 
    for j in range(odd+1):
        y = [ ] 
        for k in range(even+1):
            z =[ ] 
            for l in range(n+1):
                z.append(-1) 
            y.append(z) 
        x.append(y) 
    dp.append(x) 





if (a[0]==0):
    x = 10**9 
    y = 10**9 
    if (even>0):
        x = go(1,0,even-1,odd)
    if (odd>0):
        y = go(1,1,even,odd-1) 

    print(min(x,y)) 
else:
    if (a[0]%2):
        print(go(1,1,even,odd)) 
    else:
        print(go(1,0,even,odd))
    
 
 


