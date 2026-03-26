import heapq

n = int(input())
b = list(map(int,input().split()))
t = list(map(int,input().split()))
sol=0

x = [(i,j) for (i,j) in zip(b,t)]
x.sort()

ll = []
i = 0
v = 0
ss = 0
while(i<len(x)):
    if len(ll)==0:
        heapq.heappush(ll, -x[i][1])
        ss+=x[i][1]
        v = x[i][0]
        i+=1
    while(i<len(x) and x[i][0]==v):
        heapq.heappush(ll, -x[i][1])
        ss+=x[i][1]
        i+=1
    #print(v,ll)
    ss+=heapq.heappop(ll)
    sol+=ss
    v+=1

while(ll):
    #print(ll)
    ss+=heapq.heappop(ll)
    sol+=ss
    
print(sol)