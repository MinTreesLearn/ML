from sys import stdin, stdout
def get_ints(): return map(int, stdin.readline().split())
def PRINT(s): stdout.write(s + '\n')
# n = int(stdin.readline())
# arr = [int(x) for x in stdin.readline().split()]

def logic(s):
    try:
        l = s.index('(')
        r = s.rindex(')')
    except:
        PRINT('0')
        return
    if l >= r:
        PRINT('0')
        return
    L = [l]
    R = [r]
    n = 2
    while True:
        # find the next positions of l and r
        l += 1
        while l < len(s) and s[l] != '(':
            l += 1
        r -= 1
        while r > 0 and s[r] != ')':
            r -= 1
        if l >= r:
            break
        L.append(l)
        R.append(r)
        n += 2
    PRINT('1')
    PRINT(str(n))
    PRINT(' '.join([str(x+1) for x in L]) + ' ' + ' '.join([str(x+1) for x in R[::-1]]))
    #return L + R[::-1]

s = stdin.readline()[:-1]

logic(s)

##import random as r
##for k in range(10000):
##    s = ''
##    for i in range(200):
##        s += r.choice(['(',')'])
##    res = logic(s)
##    S = ''
##    for i in range(len(s)):
##        if i not in res:
##            S += s[i]
##
##    if logic(S) != None:
##        print('issue')
##        print(s,S)
