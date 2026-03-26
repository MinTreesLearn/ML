# https://codeforces.com/problemset/problem/1294/D

import sys
q, x = map(int, sys.stdin.readline().split(" ")) 
 
dict = {}
mex = 0
 
for i in range(q):
    y = int(sys.stdin.readline())
    y_ = y % x # y init
    
    if y_ in dict:
        new_y_ = y_ + x*dict[y_]
        dict[y_] += 1
        dict[new_y_] = 0
    else:
        dict[y_] = 1
        
        
    # print(dict)
    while mex in dict:
        mex+=1
    print(mex)


