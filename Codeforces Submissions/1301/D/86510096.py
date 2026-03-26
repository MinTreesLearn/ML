import math
import collections
import sys


def inpu():
    return input().split(' ')


def inti(a):
    for i in range(len(a)):
        a[i] = int(a[i])
    return a


def inp():
    a = inpu()
    a = inti(a)
    return a


def solution():
    n, m, k = map(int, input().split())
    c = 0
    i = 0
    if k > 4*n*m-2*n-2*m:
        print("NO")
        exit(0)
    d = []
    m -= 1
    while True:
        if i == 0:
            if k <= m and m > 0:
                d.append([k, "R"])
                break
            if m > 0:
                d.append([m, "R"])
                c += m
            if c+m >= k and m > 0:
                d.append([k-c, "L"])
                break
            elif m > 0:
                d.append([m, "L"])
                c += m
            d.append([1, "D"])
            c += 1
            if c == k:
                break
        elif i != n-1:
            if c+m >= k and m > 0:
                d.append([k-c, "R"])
                break
            elif m > 0:
                d.append([m, "R"])
                c += m
            if (k-c)//3 < m:
                if (k-c)//3 > 0:
                    d.append([(k-c)//3, "UDL"])
                if (k-c) % 3 > 0:
                    d.append([1, "UDL"[:(k-c) % 3]])
                break
            elif (k-c)//3 == m and (k-c) % 3 == 0 and m > 0:
                d.append([(k-c)//3, "UDL"])
                break
            elif m > 0:
                # print((k-c)//3,k,c)
                d.append([m, "UDL"])
                c += (m)*3
            d.append([1, "D"])
            c += 1
            if c == k:
                break
        else:
            if c+m >= k and m > 0:
                d.append([k-c, "R"])
                break
            elif m > 0:
                d.append([m, "R"])
                c += m
            if (k-c)//3 < m:
                if (k-c)//3 > 0:
                    d.append([(k-c)//3, "UDL"])
                if (k-c) % 3 > 0:
                    d.append([1, "UDL"[:(k-c) % 3]])
                break
            elif (k-c)//3 == m and (k-c) % 3 == 0 and m > 0:
                d.append([(k-c)//3, "UDL"])
                break
            elif m > 0:
                d.append([m, "UDL"])
                c += (m)*3
            d.append([k-c, "U"])
            break
        i += 1
        # print(c,i)
    print("YES")
    print(len(d))
    for i in d:
        print(*i)


# for _ in range(int(input())):
solution()
