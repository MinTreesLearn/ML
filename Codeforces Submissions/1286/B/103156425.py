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
unused = {};
def main():
    B();

def checkPossibility(root,v,c):
    count = 0;
    for i in range(len(v[root])):
        if not checkPossibility(v[root][i],v,c):
            return False;
        count += c[v[root][i]];
    if c[root] <= count + len(v[root]):
        return True;
    return False;

b = True;
def dfs(root,v,c):
    global b;
    l = [];
    for i in range(len(v[root])):
        l.extend(dfs(v[root][i],v,c));
    if c[root] > len(l):
        b = False;
    l.insert(c[root],root);
    return l;

def B():
    n = pi();
    v = [[] for i in range(n)];
    c = [0 for i in range(n)];
    root = -1;
    for i in range(n):
        [p,ci] = ti();
        if p == 0:
            root = i;
        else:
            v[p-1].append(i);
        c[i] = ci;
    
    l = dfs(root,v,c);
    ans = [0 for i in range(n)];
    if b:
        for i in range(n):
            ans[l[i]] = i+1;
        print("YES");
        print(*ans);
    else: print("NO");

main();