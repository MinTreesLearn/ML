import sys
input = sys.stdin.buffer.readline
n = int(input())
a = list(map(int, input().split()))
stk = []
for i in a:
    now_sum = i
    now_cnt = 1
    while stk and now_sum * stk[-1][1] < stk[-1][0] * now_cnt:
        temp_sum, temp_cnt = stk.pop()
        now_sum += temp_sum
        now_cnt += temp_cnt
    stk.append((now_sum, now_cnt))
for i in stk:
    temp_ans = str(i[0]/i[1])
    for j in range(i[1]):
        print(temp_ans)
