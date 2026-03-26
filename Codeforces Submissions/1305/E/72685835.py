import math
import sys

n,m=[int(s) for s in input().split()]
ans=[]

curr_balance=0
for i in range(1,n+1):
    new_balance=math.floor((i-1)/2);
    if curr_balance+new_balance > m:
        break
    curr_balance+=new_balance;
    ans.append(i);

if curr_balance<m:
    if len(ans)==n:
        print(-1)
        sys.exit()
    
    remaining_balance = m-curr_balance
    number_index = remaining_balance*2 - 1
    
    if ans[-1-number_index]+ans[-1] <= 1000000000:
        ans.append(ans[-1-number_index]+ans[-1])
        
num_to_add=ans[-1]+1
for i in range(len(ans)+1,n+1):
    if ans[-1]+num_to_add <= 1000000000:
        ans.append(ans[-1]+num_to_add)
    else:
        break;

if len(ans)<n:
    print(-1)
    sys.exit()
    
for i in ans:
    print(i," ")
