from math import inf, sqrt

def main():
    t = int(input())
    while t:
        a, b, c = list(map(int, input().split(' ')))
        res = inf
        res_list = list()
        for i in range(1, 10001):
            for j in range(i, 20001 ,i):
                now = abs(j - b) + abs(i - a)
                if c <= j :
                    now += j - c
                    k = j
                else:
                    now += min(abs(c - j * (c // j)), abs(c - j * (c // j + 1)))
                    if abs(c - j * (c // j)) < abs(c - j * (c // j + 1)):
                        k = j * (c // j)
                    else:
                        k = j * (c // j + 1)
                if now < res:
                    res = now
                    res_list = (i, j, k)
        '''
        # wrong in 137 10000 10000, answer is 137 10001 10001
        for j in range(1, 10001):
            now = abs(j - b)
            if a >= j:
                now += a - j
                i = j
            else:
                minv = inf
                best_i = 0
                for i in range(1, int(sqrt(j)) + 1):
                    if j % i == 0:
                        if abs(i - a) < minv:
                            minv = abs(i - a)
                            best_i = i
                        if abs(j // i - a) < minv:
                            minv = abs(j // i - a)
                            best_i = j // i 
                i = best_i
                now += minv
            if c <= j :
                now += j - c
                k = j
            else:
                now += min(abs(c - j * (c // j)), abs(c - j * (c // j + 1)))
                if abs(c - j * (c // j)) < abs(c - j * (c // j + 1)):
                    k = j * (c // j)
                else:
                    k = j * (c // j + 1)
            if now < res:
                res = now
                res_list = (i, j, k)
        '''
        print(res)
        print(*res_list)
        t -= 1
    return

main()