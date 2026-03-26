t=int(input())
for i in range(t):
   n=int(input())
   l=list(map(int,input().split()))
   l.sort(reverse=True)
   l=list(map(str,l))
   print(" ".join(l))
