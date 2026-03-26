# 2022-07-03T13:11:49Z


def proc(n, s):
    s = list(map(ord, s))
    while True and len(s) > 1:
        to_remove = []
        for i in range(len(s)):
            if i == 0:
                if s[i] == s[i + 1] + 1:
                    to_remove.append(i)
            elif i == len(s) - 1:
                if s[i] == s[i - 1] + 1:
                    if not to_remove or s[i] > s[to_remove[0]]:
                        to_remove = [i]
                    elif s[i] == s[to_remove[0]]:
                        to_remove.append(s[i])
            else:
                if s[i] == s[i + 1] + 1 or s[i] == s[i - 1] + 1:
                    if not to_remove or s[i] > s[to_remove[0]]:
                        to_remove = [i]
                    elif s[i] == s[to_remove[0]]:
                        to_remove.append(s[i])
        if not to_remove:
            break

        ns = []
        to_remove = set(to_remove)
        for i in range(len(s)):
            if i in to_remove:
                continue
            ns.append(s[i])
        s = ns

    # print(list(map(chr, s)))
    return n - len(s)


n = int(input())
s = input().strip()

ans = proc(n, s)
print(ans)

"""
bacab[c]ab

bacabab

"""
