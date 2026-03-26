import sys

def tobase(n, k):
  ret = []
  while n:
    ret.append( n % k)
    n //= k
  return ret

ncase = int(sys.stdin.readline().strip())
while ncase:
  ncase -= 1

  n, k = map(int, sys.stdin.readline().split())
  a    = list(map(int, sys.stdin.readline().split()))

  b = [ tobase(i, k) for i in a ]
  mlen = max([len(i) for i in b ])

  res = []
  for i in range(mlen):
    m = 0
    for x in b:
      try :
        m += x[i]
      except IndexError:
        pass
    res.append(m)
  
  if res and max(res) > 1: 
    print("NO")
  else:
    print("YES")
    

  	   				 			 	 	  				   		 	