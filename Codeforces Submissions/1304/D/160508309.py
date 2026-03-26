from sys import stdin
input = stdin.readline

inp = lambda : list(map(int,input().split()))

def assign1(ans , take , what):

    if(what == '<'):
        ans.extend(take)
    else:
        if(len(ans)):
            this = ans.pop()
            ans.extend(take[::-1])
            ans.append(this)
        else:
            ans.extend(take[::-1])

def assign2(ans , take , what):

    if(what == '<'):

        if(len(ans)):
            this = ans.pop()
            ans.extend(take[::-1])
            ans.append(this)
        else:
            ans.extend(take[::-1])

    else:
        ans.extend(take)
    

def answer():

    take = [n]
    minans = []

    for i in range(n - 2):

        take.append(n - i - 1)
        if(a[i] != a[i + 1]):
            assign2(minans , take , a[i])
            take = []

    take.append(1)
    assign2(minans , take , a[-1])
    print(*minans)
        

    take =[1]
    maxans = []
    for i in range(n - 2):

        take.append(i + 2)
        if(a[i] != a[i + 1]):
            assign1(maxans , take , a[i])
            take = []

    take.append(n)
    assign1(maxans , take , a[-1])
    print(*maxans)

for T in range(int(input())):

    s = input().split()

    n = int(s[0])
    a = s[1]
    
    answer()
