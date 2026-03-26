# 6 5
# 5 0 3 1 2
# 1 8 9 1 3
# 1 2 3 4 5
# 9 1 0 3 7
# 2 3 0 6 3
# 6 4 1 7 0
import sys
input = lambda: sys.stdin.buffer.readline().decode().strip()

max_a = 10**9
min_a = 0

def solve():
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for i in range(n)]

    # binary search where tail remains in the portion and head does not
    tail, head = 0, 1 + 10**9
    while tail + 1 != head:
        mid = head + tail >> 1
        
        # run the check for mid
        t = mid
        is_present = [[] for i in range(2**m)]
        for i, ai in enumerate(a):
            num = 0
            for aik in ai:
                # print(t, aik, head, tail)
                num  = num * 2 + int(t <= aik)
            is_present[num].append(i)
        
        check = 0
        for pair1 in range(2**m):
            for pair2 in range(2**m):
                if check: break
                if pair2 | pair1 == 2**m - 1:
                    if len(is_present[pair1]) > 0 and len(is_present[pair2]) > 0:
                        check = 1
                        ans = [is_present[pair1][0], is_present[pair2][0]]
                        break
            
        # print(check, t, is_present)
        #########################
        if check:
            tail = mid
        else:
            head = mid
    try:
        print(ans[0] + 1, ans[1] + 1)
    except:
        print(1, 1)

solve()

        


            
            


