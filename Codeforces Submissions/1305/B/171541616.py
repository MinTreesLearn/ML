s = input()
l = []
for j in range(len(s)):
    l.append(s[j])
# bracketOpen = []
# bracketClose = []
ans = []
# if len(s)%2==0 or len(s)%2==1:
#     for j in range(len(s)):
#         if l[j]=="(":
#             bracketOpen.append(j+1)
#     # for j in range(len(s)//2,len(s)):
#         elif l[j]==")":
#             bracketClose.append(j+1)
            
#     if len(bracketClose)>len(bracketOpen):
#         ans = []
#         for j in range(len(bracketOpen)):
#             ans.append(bracketOpen[j])
#         for j in range(len(bracketOpen)):
#             ans.append(bracketClose[j])
#     else:
#         ans = []
#         for j in range(len(bracketClose)):
#             ans.append(bracketOpen[j])
#         for j in range(len(bracketClose)):
#             ans.append(bracketClose[j])
#     if len(ans)==0:
#         print(0)
#     else:
#         print(1)
#         print(len(ans))
        # print(*ans)  
f = 0
r  = len(s) - 1
while f < r:
    if l[f]=="(" and l[r]==")":
        ans.append(f+1)
        ans.append(r+1)
        f+=1
        r-=1
    elif l[f]=="(" and l[r]!=")":
        r-=1
    elif l[f]!="(" and l[r]==")":
        f+=1
    else:
        f+=1
        r-=1
if len(ans)==0:
    print(0)
else:
    print(1)
    print(len(ans))
    ans.sort()
    print(*ans)