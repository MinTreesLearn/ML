
import string
from sys import  stdin
input=stdin.readline
read=lambda :map(lambda s:int(s),input().strip().split())
readi=lambda :int(input())
from collections import defaultdict,Counter
from  bisect import  bisect_left as bl,bisect_right as br
from random import randint
from math import gcd,ceil
RANDOM = randint(1, 10 ** 9)
class Wrapper(int):
    def __hash__(self):
        return super(Wrapper, self).__hash__() ^ RANDOM
def gen(s,k):
    i=0
    if (len(s)-k)%2==0:
    # if k%2==0:
        return s[k:]+s[:k]
    else:
        return s[k:]+s[:k][::-1]
    return s
# print(gen("abcdep",2))
for _ in range(readi()):
    n=readi()
    # s="ba"*(2500)
    s=input().strip()
    if n==1:
        print(s,1,sep="\n")
        continue
    ind=[]
    mn=min(s)
    for id,i in enumerate(s):
        if i==mn:
            ind.append(id)
    ans="z"*n
    k=None
    for i in ind:
        t=gen(s,i)
        # print(t,i)
        if t<ans:
            ans=t
            k=i
    print(ans,k+1,sep="\n")
