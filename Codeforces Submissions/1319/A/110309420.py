import collections
input()
q=collections.Counter(zip(input().split(),input().split()))
if q[('1','0')]:
    print((q[('0','1')])//q[('1','0')]+1)
else:
    print(-1)