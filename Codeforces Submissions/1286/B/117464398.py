 ######      ###      #######    #######    ##      #     #####        ###     ##### 
 #     #    #   #          #        #       # #     #    #     #      #   #     ###  
 #     #   #     #        #         #       #  #    #   #       #    #     #    ###  
 ######   #########      #          #       #   #   #   #           #########    #   
 ######   #########     #           #       #    #  #   #           #########    #   
 #     #  #       #    #            #       #     # #   #    ####   #       #    #   
 #     #  #       #   #             #       #      ##   #    #  #   #       #        
 ######   #       #  #######     #######    #       #    #####  #   #       #    #   
 
from __future__ import print_function # for PyPy2
# from itertools import permutations
# from functools import cmp_to_key	# for adding custom comparator
# from fractions import Fraction
from collections import *
from sys import stdin
# from bisect import *
from heapq import *
from math import *
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

root = 1
n, = gil()
c = [0]*(n+1)
children = [[] for _ in range(n+1)]

for node in range(1, n+1):
	parent, ci = gil()
	c[node] = ci
	if parent == 0:root = node
	children[parent].append(node)

# print(children)

depth = [0]*(n+1)
st = [root]

while st:
	p = st.pop()
	for ch in children[p]:
		depth[ch] = depth[p] + 1
		st.append(ch)

nodes = list(range(1, n+1))
nodes.sort(key=lambda x:depth[x])
lst = [None for _ in range(n+1)]

while nodes :
	node = nodes.pop()
	down = []
	for ch in children[node]:
		for chi in lst[ch]:
			down.append(chi)

	if len(down) < c[node]:
		print('NO')
		exit()

	lst[node] = down

	down.insert(c[node], node)


# print(lst[root])
val = [0]*(n+1)
s = 1
for ch in lst[root]:
	val[ch] = s
	s += 1
print('YES')
print(*val[1:])