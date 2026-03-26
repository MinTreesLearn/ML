from sys import stdin, stdout
import bisect
at_dist = []
mx = []
cow = []
sums = []
m = []
res_p = 0
res_r = 1

def modInverse(a, m) : 
    return power(a, m - 2, m)
      
# To compute x^y under modulo m 
def power(x, y, m) : 
      
    if (y == 0) : 
        return 1
          
    p = power(x, y // 2, m) % m 
    p = (p * p) % m 
  
    if(y % 2 == 0) : 
        return p  
    else :  
        return ((x * p) % m) 
  
# Function to return gcd of a and b 
def gcd(a, b) : 
    if (a == 0) : 
        return b 
          
    return gcd(b % a, a) 

def update(p, r):
    global res_p
    global res_r
    if p > res_p:
        res_p = p
        res_r = r
    elif p == res_p:
        res_r += r
        res_r = int(res_r % 1000000007)

def set_way(f):
    right = bisect.bisect_right(cow[f],at_dist[f])
    left = bisect.bisect_right(cow[f], mx[f] - at_dist[f])
    mn = min(left, right)
    mul = right*left - mn
    plus = left + right
    if mul > 0:
        sums[f] = 2
        m[f] = mul
    elif plus > 0:
        sums[f] = 1
        m[f] = plus
    else:
        sums[f] = 0
        m[f] = 1

def do_up(f):
    right = at_dist[f]
    b = bisect.bisect_right(cow[f],at_dist[f])
    left = mx[f] - at_dist[f]
    if right >= left:
        b-=1
    if b > 0:
        sums[f] = 2
        m[f] = b
    else:
        sums[f] = 1
        m[f] = 1

def main():
    global res_p
    global res_r
    global mx
    n,M = list(map(int, stdin.readline().split()))
    grass = list(map(int, stdin.readline().split()))
    for i in range(n+1):
        at_dist.append(0)
        sums.append(0)
        m.append(0)
        cow.append([])
    for i,x in enumerate(grass):
        at_dist[x] += 1
    mx = list(at_dist)
    for _ in range(M):
        f,h = list(map(int, stdin.readline().split()))
        cow[f].append(h)
    
    for i in range(1,n+1):
        cow[i].sort()
        set_way(i)
        res_p += sums[i]
        res_r *= m[i]
    t_p = res_p
    t_r = res_r
    for i in range(n):
        f = grass[i]
        t_p -= sums[f]
        t_r = int(t_r* modInverse(m[f], 1000000007) % 1000000007)
        at_dist[f] -=1
        left = mx[f] - at_dist[f]
        ii = bisect.bisect_left(cow[f], left)
        if ii < len(cow[f]) and cow[f][ii] == left:
            do_up(f)
            temp_p = t_p + sums[f]
            temp_r = t_r * m[f]
            update(temp_p, temp_r)
        set_way(f)
        t_p += sums[grass[i]]
        t_r = (t_r * m[grass[i]]) % 1000000007
    stdout.write(str(res_p) + " " + str(int(res_r % 1000000007)))
    
main()
            