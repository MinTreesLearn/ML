import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP3/output.txt",'w')
# sys.stdin=open("CP3/input.txt",'r')

# m=pow(10,9)+7
s=input()
pref=defaultdict(dict)
pref[0]={s[0]:1}
for j in range(1,len(s)):
    pref[j]=pref[j-1].copy()
    pref[j][s[j]]=pref[j].get(s[j],0)+1
# print(pref)
q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    if l==r or s[l-1]!=s[r-1]:
        print("Yes")
        continue
    c=0
    if l==1:
        c=len(pref[r-1])
    else:
        for j in pref[r-1]:
            if pref[l-2].get(j,0)<pref[r-1][j]:
                c+=1
    if c>2:
        print("Yes")
    else:
        print("No")