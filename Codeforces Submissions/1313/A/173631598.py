from unittest import async_case


t = int(input())

def solve(a, b, c):
    ans = 0
    if a > 0:
        ans += 1
        a -= 1
    if b > 0:
        ans += 1
        b -= 1
    if c > 0:
        ans += 1
        c -= 1
    if c == max(a, b, c):
        if a > 0 and c > 0:
            ans += 1
            a -= 1
            c -= 1
        if b > 0 and c > 0:
            ans += 1
            b -= 1
            c -= 1
        if a > 0 and b > 0:
            ans += 1
            a -= 1
            b -= 1
    else:
        if a > 0 and b > 0:
            ans += 1
            a -= 1
            b -= 1
        if a > 0 and c > 0:
            ans += 1
            a -= 1
            c -= 1
        if b > 0 and c > 0:
            ans += 1
            b -= 1
            c -= 1
    if a > 0 and b > 0 and c > 0:
        ans += 1
    return ans
    

for _ in range(t):
    a, b, c = map(int, input().split())
    print(solve(a, b, c))
				 		   		  				   		 			