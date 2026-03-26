def f(x):
   return x%2

t=int(input())
for i in range(t):
   n=int(input())
   l=list(map(int,list(input())))
   if n==1:
      print(-1)
   else:
      ll=list(map(f,l))
      if ll.count(1)<=1:
         print(-1)
      else:
         s=""
         k=0
         for j in range(len(ll)):
            if ll[j]==1 and k<2:
               k=k+1
               s=s+str(l[j])
         print(s)




