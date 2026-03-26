def get_ints():
    return map(int, input().strip().split())

def get_list():
    return list(map(int, input().strip().split()))

def get_string():
    return input().strip()

# For fast IO use sys.stdout.write(str(x) + "\n") instead of print
import sys
import math
input = sys.stdin.readline

for t in range(int(input().strip())):
    n = int(input().strip())
    arr = get_list()
    prefix_len, suffix_len = 0, 0
    
    for i in range(n):
        if arr[i] >= i:
            prefix_len += 1
        else:
            break
        
    for i in range(n-1, -1, -1):
        if arr[i] >= n-i-1:
            suffix_len += 1
        else:
            break
    
    if prefix_len + suffix_len > n:
        print("Yes")
    else:
        print("No")