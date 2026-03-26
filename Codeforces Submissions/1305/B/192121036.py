strings = input()

left, right = 0, len(strings)-1
count = 0
ans=set()
while left < right:
    if strings[right] == "(":
        right-=1
    else:
        if strings[left] == "(":
            ans.add(right+1)
            ans.add(left+1)
            count+=1
            right-=1
            left+=1
            
    if strings[left] == ")":
        left+=1
        

if count:
    print(1)
    print(len(ans))
    ans = list(ans)
    ans.sort()
    print(*ans)
else:
    print(0)