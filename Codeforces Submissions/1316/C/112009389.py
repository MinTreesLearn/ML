
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))

n,m,p = get_ints()
a = get_list()
b = get_list()

i =0
while i<n:
    if a[i]%p != 0:
        break
    i+=1

j =0
while j<m:
    if b[j]%p != 0:
        break
    j+=1

print(i+j)

