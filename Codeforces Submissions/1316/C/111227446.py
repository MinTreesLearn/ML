from pprint import pprint
import sys
read = sys.stdin.buffer.read
n,m,p, *dat = map(int, read().split())
data = dat[:n]
datb = dat[n:]
for i in range (n):
    if data[i]%p != 0:
        inda = i
        break
for i in range (m):
    if datb[i]%p != 0:
        indb = i
        break
print(indb + inda)