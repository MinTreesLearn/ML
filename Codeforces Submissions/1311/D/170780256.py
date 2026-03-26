import sys
import math
import itertools
input = sys.stdin.readline


def solve():
    a , b , c = map(int , input().split())
    ansA , ansB , ansC = 1 , 1 , 1
    ans = (a-1)+(b-1)+(c-1)
    i = 1
    while i <= 2*a:
        tmpA = i
        tmpB = i
        tmpC = tmpB * (c//tmpB)
        tmpAns = abs(a-tmpA)+abs(b-tmpB)+abs(c-tmpC)
        if tmpAns < ans:
            ans = tmpAns
            ansA,ansB,ansC = tmpA,tmpB,tmpC
        tmpC = tmpB * (c//tmpB) + tmpB
        tmpAns = abs(a-tmpA)+abs(b-tmpB)+abs(c-tmpC)
        if tmpAns < ans:
            ans = tmpAns
            ansA,ansB,ansC = tmpA,tmpB,tmpC
        while tmpB <= 2*b:
            tmpB += i
            tmpC = tmpB * (c//tmpB)
            tmpAns = abs(a-tmpA)+abs(b-tmpB)+abs(c-tmpC)
            if tmpAns < ans:
                ans = tmpAns
                ansA,ansB,ansC = tmpA,tmpB,tmpC
            tmpC = tmpB * (c//tmpB) + tmpB
            tmpAns = abs(a-tmpA)+abs(b-tmpB)+abs(c-tmpC)
            if tmpAns < ans:
                ans = tmpAns
                ansA,ansB,ansC = tmpA,tmpB,tmpC
        i += 1
    print(ans)
    print(ansA,ansB,ansC)
for _ in range(int(input())):
    solve()
