n = int(input())
lst = [int(x) for x in input().split()][:n]
cnt, m_cnt = 0, 0
cnt2, m_cnt2 = 0, 0
if lst[0] == lst[-1] and lst[0] == 1:
  cnt = 1
  for j in range(n - 1):
    if lst[j] == 1: cnt += 1
    else: break
    if cnt > m_cnt: m_cnt = cnt
  for j in range(n - 2, 0, -1):
    if lst[j] == 1: cnt += 1
    else: break
    if cnt > m_cnt: m_cnt = cnt
for j in range(n):
  if lst[j] == 1: cnt2 += 1
  else: cnt2 = 0
  if cnt2 > m_cnt2: m_cnt2 = cnt2
print(max(m_cnt, m_cnt2))
   		    			 			  	 	   		  			