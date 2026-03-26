for _ in range(int(input())):
  [a,b]=list(map(int,input().split(" ")))
  k=(a-b)//(b+1) 
  extra=(a-b)%(b+1)
  print((a*(a+1)-(a-b+extra)*(k+1))//2)