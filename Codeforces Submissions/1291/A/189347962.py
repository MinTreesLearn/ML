t = int(input())
for i in range(t):
    n = int(input())
    x = input()
    ans = []
    for i in x:
        i = int(i)
        if i % 2 == 1:
            ans.append(i)
    if len(ans) > 1:
        print(ans[0], ans[1], sep = "")
    else:
        print(-1)