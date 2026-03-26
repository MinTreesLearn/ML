#import io, os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())

lis = list(map(int,input().split()))

connections = {}

for i in range(len(lis)):

  if str(lis[i] - i) in connections:
    a = connections[str(lis[i] - i)]
    a.append(lis[i])
    connections[str(lis[i] - i)] = a

  else:

    connections[str(lis[i] - i)] = [lis[i]]

maxi = 0

for i in connections:

  b = sum(connections[i])
  maxi = max(maxi,b)

print(maxi)