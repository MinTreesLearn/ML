T = int(input())
ANS = []
for _ in range(T):
    s = input()
    t = input()
    sl = [[] for i in range(26)]
    for i in range(len(s)):
        sl[ord(s[i]) - ord('a')].append(i)
    ans = 0
    tek = -1
    ttt = True
    #print(sl)
    for i in range(len(t)):
        l = -1
        r = len(sl[ord(t[i]) - ord('a')]) - 1
        if sl[ord(t[i]) - ord('a')] == []:
            ANS.append(-1)
            ttt = False
            break
        while r - l > 1:
            m = (l + r) // 2
            if sl[ord(t[i]) - ord('a')][m] > tek:
                r = m
            else:
                l = m
        if sl[ord(t[i]) - ord('a')][r] > tek:
            tek = sl[ord(t[i]) - ord('a')][r]
        else:
            tek = sl[ord(t[i]) - ord('a')][0]
            #tek  = -1
            ans += 1
        #print(_, tek, r, ans)
    if ttt:
        ANS.append(ans + 1)
for i in ANS:
    print(i)
