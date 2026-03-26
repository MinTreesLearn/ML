from collections import defaultdict as dd
import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
a = input()
b = input()

a_ct = dd(list)
b_ct = dd(list)

for i in range(n):
    a_ct[a[i]].append(i)
    b_ct[b[i]].append(i)
    
result = []
for key in a_ct:
    while key != '?' and a_ct[key] and b_ct[key]:
        result.append((a_ct[key].pop() + 1, b_ct[key].pop() + 1))
        
for key in b_ct:
    while key != '?' and a_ct['?'] and b_ct[key]:
        result.append((a_ct['?'].pop() + 1, b_ct[key].pop() + 1))

for key in a_ct:
    while key != '?' and b_ct['?'] and a_ct[key]:
        result.append((a_ct[key].pop() + 1, b_ct['?'].pop() + 1))
            
while a_ct['?'] and b_ct['?']:
    result.append((a_ct['?'].pop() + 1, b_ct['?'].pop() + 1))
    
print(len(result))
for v in result:
    print(*v)