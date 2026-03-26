n = int(input())
a = [int(x) for x in input().split()]
cnt, ans = 0, 0
start_cnt, end_cnt = 0, 0
check = False
for i in range(n):
    if a[i] == 1:
        cnt += 1
        if check == False:
            start_cnt += 1
    else:
        cnt = 0
        check = True
    if cnt > ans: ans = cnt
for i in range(n - 1, start_cnt, -1):
    if a[i] == 1:
        end_cnt += 1
    else: break
if start_cnt + end_cnt > ans:
    ans = start_cnt + end_cnt
print(ans)
 	       		  	 	 	 		 	 							