import copy
from collections import deque
a = int(input())
b = deque(list(map(str,input())))
if a%2 != 0:
    print(-1)
else:
    a=0
    for i in b:
        if i == "(":
            a+=1
        else:
            a-=1
    if a != 0:
        print(-1)
    else:
        ans=0
        while b:
            a = b.popleft()
            stat = 0
            if a == "(":
                stat+=1
                while stat>0:
                    z = b.popleft()
                    if z == "(":
                        stat+=1
                    else:
                        stat-=1
            if a == ")":
                stat+=1
                ans+=1
                while stat!=0:
                    ans+=1
                    z = b.popleft()
                    if z == ")":
                        stat+=1
                    else:
                        stat-=1
        print(ans)
