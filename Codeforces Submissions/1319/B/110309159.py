import collections
q=collections.Counter()
input()
for i,b in enumerate(map(int,input().split())):
    q[b-i]+=b
print(max(q.values()))