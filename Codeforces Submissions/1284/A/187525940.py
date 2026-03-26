from sys import stdin
input = stdin.readline
#google = lambda : print("Case #%d: "%(T + 1) , end = '')
inp = lambda : list(map(int,input().split()))


def answer():

    
    for q in range(int(input())):

        y = int(input())
        y -= 1
        ans = a[y % n] + b[y % m]
        print(ans)



for T in range(1):

    n , m = inp()
    a = input().split()
    b = input().split()
    


    answer()
