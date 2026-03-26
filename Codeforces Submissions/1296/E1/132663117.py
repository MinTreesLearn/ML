import sys, collections, math,bisect
input = sys.stdin.readline


n = int(input())
s = input().rstrip('\n')
stack = []
for i in range(n):
    if not stack:
        stack.append([s[i],0,i])
    else:
        if stack[-1][0] <= s[i]:
            stack.append([s[i],stack[-1][1],i])
        else:
            cur = stack[-1][1] ^ 1
            temp = []
            flag = 1
            while stack and stack[-1][0] > s[i]:
                c,co,pos = stack.pop()
                if co != cur:
                    temp.append([c,co,pos])
                else:
                    flag = 0
                    break
            if flag:
                stack.append([s[i],cur,i])
                while temp:
                    stack.append(temp.pop())
            else:

                break

if len(stack) != n:
    print('NO')
else:
    ans = [''] * n
    for i in range(n):
        ans[stack[i][2]] = str(stack[i][1])
    print('YES')
    print(''.join(ans))











