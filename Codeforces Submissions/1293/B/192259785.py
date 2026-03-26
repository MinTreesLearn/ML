import sys
# sys.stdin=open("input.txt","r")
# sys.stdout=open("output.txt","w")


n=int(input())
ans,num=0,n
for i in range(1,n+1):
    ans+=(1/num)
    num-=1
print(ans)