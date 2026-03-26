import sys
import math
input = sys.stdin.readline
from functools import cmp_to_key;

def pi():
    return(int(input()))
def pl():
    return(int(input(), 16))
def ti():
    return(list(map(int,input().split())))
def ts():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
mod = 998244353;
f = [];
def fact(n,m):
    global f;
    f = [1 for i in range(n+1)];
    f[0] = 1;
    for i in range(1,n+1):
        f[i] = (f[i-1]*i)%m;

def fast_mod_exp(a,b,m):
    res = 1;
    while b > 0:
        if b & 1:
            res = (res*a)%m;
        a = (a*a)%m;
        b = b >> 1;
    return res;

def inverseMod(n,m):
    return fast_mod_exp(n,m-2,m);

def ncr(n,r,m):
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    B();        

def B():
    s = ts();
    t = pi();
    c = [[0 for j in range(len(s))] for i in range(26)];
    for i in range(26):
        for j in range(len(s)):
            if ord(s[j])-ord("a") == i:
                c[i][j] = c[i][j-1] + 1 if j > 0 else 1;
            else:
                c[i][j] = c[i][j-1] if j > 0 else 0;
    for i in range(t):
        [l,r] = ti();
        count = 0;
        for j in range(26):
            count += (1 if c[j][r-1]-c[j][l-1] > 0 else 0);
        if s[l-1] != s[r-1] or l == r:
            print("Yes");
        elif count >= 3:
            print("Yes");
        else:
            print("No");

    

main();