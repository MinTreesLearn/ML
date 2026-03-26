n = int(input())
s = input()
ans = []
c = 0
for i in range(n):
    c = c + 1 if s[i] == '(' else c - 1 
    ans.append(c)
c = 0
for i in range(n):
    if(ans[i] < 0):
        c += 1 
    elif(ans[i] == 0 and ans[i - 1] < 0):
        c += 1
if(ans[-1] == 0):
    print(c)
else:
    print(-1)
    
