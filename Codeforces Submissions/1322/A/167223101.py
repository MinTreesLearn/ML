from collections import Counter


n = int(input())
s = input()
count = Counter(s)
open = closed = 0
if count['('] != count[')']:
    print(-1)
else:
    res = 0
    balance = 0
    prev = ''
    for i in range(len(s)):
        if s[i] == '(':
            balance += 1
        else:
            balance -= 1
        if balance < 0:
            res += 1
            prev = '-'
        elif balance == 0:
            if prev == '-':
                res += 1
            prev = ''
        else:
            prev = ''
    print(res)
