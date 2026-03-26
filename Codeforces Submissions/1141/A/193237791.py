n, m=map(int ,input().split())
x, r=0, m/n
for i in[2,3]: 
   while r % i == 0:
       r/=i
       x+=1
print(x if r==1 else -1)