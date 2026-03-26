#Lockout 1 Round #4
#Problem C
import sys
input = lambda: sys.stdin.readline()[:-1]
get_int = lambda: int(input())
get_int_iter = lambda: map(int, input().split())
get_int_list = lambda: list(get_int_iter())
flush = lambda: sys.stdout.flush()

#DEBUG
DEBUG = False
def debug(*args):
    if DEBUG:
        print(*args)

def solve_case(n,x,nums):
    val = max(nums)
    if x < val:
        if x in nums:
            return 1
        return 2
    if x % val == 0:
        return x // val
    return x // val + 1
    

for _ in range(get_int()):
    n,x = get_int_iter()
    nums = get_int_list()
    print(solve_case(n,x,nums))
