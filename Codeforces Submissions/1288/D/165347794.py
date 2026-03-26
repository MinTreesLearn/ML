def solve(a):
    m, n = len(a), len(a[0])
    maxx = max(max(t) for t in a)
    def ok(t):
        idx = [-1] * 256
        maxm = 1 << n
        for i in range(m):
            mask = 0
            for j in range(n):
                if a[i][j] >= t: mask |= 1 << j
            if idx[mask] == -1:
                idx[mask] = i
        for i in range(maxm):
            if idx[i] == -1: continue
            for j in range(i, maxm):
                if idx[j] == -1: continue
                if (i | j) == maxm - 1: return [idx[i], idx[j]]
        return [-1, -1]

    l, r = 0, maxx
    while l <= r:
        mid = (l + r) // 2
        if ok(mid) != [-1, -1]:
            l = mid + 1
        else:
            r = mid - 1
    return ok(r)

m, n = map(int, input().split())
a = []
for i in range(m):
    a.append([int(i) for i in input().split()])
res = solve(a)
print(res[0] + 1, res[1] + 1)

# def cutThemAll(lengths, minLength):
#     for i in range(len(lengths) - 1):
#         if lengths[i] + lengths[i+1] >= minLength:
#             return "Possible"
#     return "Impossible"

# ls = [3,5,6]
# print(cutThemAll(ls, 12))

# def getUniqueCharacter(s):
#     cnt = [0] * 26
#     for c in s:
#         cnt[ord(c) - ord('a')] += 1
#     for i in range(len(s)):
#         if cnt[ord(s[i]) - ord('a')] == 1:
#             return i + 1
#     return -1

# print(getUniqueCharacter("madam"))


# from cmath import log
# from collections import Counter
# from dis import findlabels

# base = 10**9 + 7
# def findRight(a):
#     # find the index of the first less one in the left side, for every a[i]
#     n = len(a)
#     st, res = [], [0] * n
#     for i in range(n - 1, -1, -1):
#         while len(st) and a[st[-1]] >= a[i]:
#             st.pop()
#         res[i] = n if len(st) == 0 else st[-1]
#         st.append(i)
#     return res

# def findLeft(a):
#     # find the index of the first less or equal one in the right side, for every a[i]
#     n = len(a)
#     st, res = [], [0] * n
#     for i in range(n):
#         while len(st) and a[st[-1]] > a[i]:
#             st.pop()
#         res[i] = -1 if len(st) == 0 else st[-1]
#         st.append(i)
#     return res

# def findTotalPower(a):
#     # In order to avoid repeated calculations, 
#     #   the left side finds the first element less than a[i], 
#     #   and the right side finds the first element less than or equal to a[i]
#     left = findLeft(a)
#     right = findRight(a)
    
#     n, res = len(a), 0
#     s = [0] * (n + 1)
#     ss = [0] * (n + 2)

#     # s means the prefix sum of a
#     for i in range(n): s[i+1] = s[i] + a[i]
#     # ss meams the prefix sum of s
#     for i in range(n + 1): ss[i+1] = ss[i] + s[i]

#     for i in range(n):
#         # every left one could be the leader of subarray, which can be combined with the ending on the right
#         l = i - left[i]
#         # every right one could be the ending of subarray, which can be combined with the leader on the left
#         r = right[i] - i
        
#         # find the sum(sum([i, r]))
#         now = ((ss[right[i] + 1] - ss[i + 1]) - r * s[i]) % base
#         # find the sum(sum([i, r])) * a[i] * (i-left)
#         res += ((now * l) % base * a[i]) % base

#         # find the sum(sum([l, i]))
#         now = (s[i] * (l - 1) - (ss[i] - ss[left[i] + 1])) % base
#         # find the sum(sum([l, i])) * a[i] * (right-i)
#         res += ((now * r) % base * a[i]) % base
#         res %= base

#     return res % base


# ls = [2,3,2,1]
# res = findTotalPower(ls)
# print(res)