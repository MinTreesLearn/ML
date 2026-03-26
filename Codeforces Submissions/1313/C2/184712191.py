
num_inp=lambda: int(input())
arr_inp=lambda: list(map(int,input().split()))
sp_inp=lambda: map(int,input().split())
str_inp=lambda:input()
inf = float('inf')
n = int(input())
a = [*map(int, input().split())]
 
for x in 0, 1:
    stack = [-1]
    s = [0] * n
    for i in range(n - 1, -1, -1):
        while a[i] < a[stack[-1]] and stack[-1] != -1:
            stack.pop()
        s[i] = (n - i) * a[i] if stack[-1] == -1 else s[stack[-1]] + a[i] *(stack[-1] - i)
        stack += [i]

    a = a[::-1]
    if x:
        ri = s[:][::-1]
    else:
        le = s[:]
        
s = [i + j - k for i, j, k in zip(le, ri, a)]
x = s.index(max(s))
 
for i in range(x + 1, n):
    a[i] = min(a[i], a[i - 1])
 
for i in range(x - 1, -1, -1):
    a[i] = min(a[i], a[i + 1])
 
print(*a)				 	