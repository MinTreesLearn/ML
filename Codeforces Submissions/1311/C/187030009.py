t = int(input())
import bisect

for _ in range(t):
    n, m = map(int, input().split())
    s = input()
    p = sorted(list(map(int,input().split())))
    counter = [0]*26
    for i in range(1,n+1):
        counter[ord(s[i-1])-ord('a')] += m-bisect.bisect_left(p,i)+1
    print(*counter)

