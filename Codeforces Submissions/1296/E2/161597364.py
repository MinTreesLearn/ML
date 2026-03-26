n = int(input())
s = str(input())

ans = [1]*n 
maxer = [0]*26

for i in range(n):
    c = s[i]
    for j in range(ord(c) - ord('a') + 1, 26):
        ans[i] = max(ans[i],maxer[j]+1)
    maxer[ord(c) - ord('a')] = ans[i]

print(max(ans))
print(*ans)