from sys import stdin
input = stdin.readline


def answer():

    if(a.count('(') != a.count(')')):return -1

    ans = 0
    bal , where = 0 , -1 
    for i in range(n):

        if(a[i] == '('):bal += 1
        else:
            bal -= 1
            if(bal < 0 and where == -1):
                where = i

        if(bal == 0 and where != -1):
            ans += i - where + 1
            where = -1

    return ans
    

for T in range(1):

    n = int(input())

    a = input().strip()


    print(answer())
