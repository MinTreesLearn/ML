def checker(n,s):
    l = 0
    r = 0
    i = 0
    ans = 0
    while i < n:
        while s[i] =="(":
            if l!= 0:
                l -= 1
                i += 1
            else:
                r += 1
                i += 1
            if i == n:
                break
        if i == n:
            break
        while s[i] == ")":
            l += 1
            if l > r:
                ans += 1
            else:
                r -= 1
                l -= 1
            i += 1
            if i == n:
                break
    if (l!=0) or (r != 0):
        return -1
    else:
        return 2*ans
# print(checker(8,"))((())("))
n = int(input())
s = str(input())
print(checker(n,s))
    