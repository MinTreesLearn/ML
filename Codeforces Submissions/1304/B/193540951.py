n, m = map(int,input().split())
t = []
ans = ans1 = ""
for i in range(n):
    s= input()
    r = s[::-1]
    if r in t:
        ans += r
    elif s==r:
        ans1 = s
    t.append(s)
anss = ans+ans1+ans[::-1]
print(len(anss),anss,end="")
