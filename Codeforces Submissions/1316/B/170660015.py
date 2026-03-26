from audioop import reverse
from sys import stdin, stdout
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_arr(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
t = int(input())
while t:
    t-=1
    n = int(input())
    s = get_string()
    s1 = s
    s2 = s
    # print(s2)    
    ans = 0
    for i in range(0,n):
        if (n-i)%2==0:
            s3 = s1[0:i]
            s4 = s[i:n] + s3
            if s4<s2:
                ans = i
            s2 = min(s2,s4)
            # print(s[i:n])
            # print(s3[::-1])
            # print(s4)
        else:
            s3 = s1[0:i]
            s4 = s[i:n] + s3[::-1]
            if s4<s2:
                ans = i
            s2 = min(s2,s4)
            # print(s[i:n])
            # print(s3[::-1])
            # print(s4)
    print(s2)     
    print(ans+1)   


 

