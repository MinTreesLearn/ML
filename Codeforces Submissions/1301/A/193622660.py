# from collections import Counter
ints = lambda: list(map(int, input().split()))
tw = lambda n: (n&(n-1)==0) and n!=0

# import sys
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

def solve(): 
    # by Azimjonm2333
    a=input()
    b=input()
    c=input()
    for i in range(len(a)):
        if c[i]!=b[i] and a[i]!=c[i]: print('NO'); return
    print("YES")
    
t=1
t=int(input())
for i in range(t): solve()
