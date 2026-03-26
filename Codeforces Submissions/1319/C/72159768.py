n = int(input())
S = list(input())
if n == 1:
    print(0)
else:
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    ans = 0
    newS = []
    for s in alphabet[::-1]:
        i = 0
        while i < len(S):
            if S[i] != s:
                newS.append(S[i])
            elif S[i] == s:
                keks = 1
                while i + 1 < len(S) and S[i + 1] == s:
                    i += 1
                    keks += 1
                if 0 < i < len(S) - 1:
                    if S[i - keks] != chr(ord(S[i]) - 1) and S[i + 1] != chr(ord(S[i]) - 1):
                        for _ in range(keks): newS.append(s)
                elif i == len(S) - 1:
                    if S[i - keks] != chr(ord(S[i]) - 1):
                        for _ in range(keks): newS.append(s)
                else:
                    if S[i + 1] != chr(ord(S[i]) - 1):
                        for _ in range(keks): newS.append(s)

            i += 1
        S = newS.copy()
        newS = []
    print(n - len(S))