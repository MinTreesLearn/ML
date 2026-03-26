import sys
a,b=map(int,input().split())
cnt=0
if(b==a):
    print(0)
    sys.exit()
if(b==0 or a==0):
    print(-1)
    sys.exit()
if(a>b):
    print(-1)
    sys.exit()
divi=b//a
while(divi%2==0):
    divi=divi//2
    cnt+=1
while(divi%3==0):
    divi=divi//3
    cnt+=1
if(b%a!=0):
    cnt=-1
if(divi==1):
    print(cnt)
else:
    print(-1)