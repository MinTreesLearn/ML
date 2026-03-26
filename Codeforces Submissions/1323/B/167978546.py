from collections import defaultdict as dd
import sys
input = lambda: sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a_conts1 = []
b_conts1 = []

cont1 = 0
for i in range(n):
    if a[i] == 1:
        cont1 += 1
    else:
        if cont1:
            a_conts1.append(cont1)
            cont1 = 0
if cont1:
    a_conts1.append(cont1)
    cont1 = 0            

cont1 = 0
for i in range(m):
    if b[i] == 1:
        cont1 += 1
    else:
        if cont1:
            b_conts1.append(cont1)
            cont1 = 0
if cont1:
    b_conts1.append(cont1)
    cont1 = 0

a_ct = dd(int)
b_ct = dd(int)

for v in a_conts1:
    a_ct[v] += 1
    
for v in b_conts1:
    b_ct[v] += 1
    
recs = []
for akey in a_ct:
    for bkey in b_ct:
         recs.append((akey, bkey, a_ct[akey] * b_ct[bkey]))
            
total = 0
for mod in range(1, int(k ** 0.5) + 1):
    if k % mod == 0:
        a = mod
        b = k // mod
        
        for ak, bk, c in recs:
            a_diff = ak - a
            b_diff = bk - b
            if a_diff >= 0 and b_diff >= 0:
                total += (a_diff + 1) * (b_diff + 1) * c 
                
            if a != b:                
                a_diff = ak - b
                b_diff = bk - a
                if a_diff >= 0 and b_diff >= 0:
                    total += (a_diff + 1) * (b_diff + 1) * c
    
print(total)