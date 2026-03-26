n = int(input())
x = input()

def remove(tmp, x):
    removed = 0
    
    if len(tmp) >= 2 and tmp[0] == x and tmp[1] == x - 1:
        removed += 1
        tmp.pop(0)

    i = 0
    n = len(tmp)
    while i < n:
        if i == 0:
            if len(tmp) >= 2 and tmp[0] == x and tmp[1] == x - 1:
                removed += 1
                tmp.pop(0)
                n -= 1
                continue
        elif i == n - 1:
            if len(tmp) >= 2 and tmp[-1] == x and tmp[-2] == x - 1:
                removed += 1
                tmp.pop(len(tmp) -1 )
                n -= 1
                continue
        elif tmp[i] == x and (tmp[i + 1] == x - 1 or tmp[i - 1] == x - 1 ):
            removed += 1
            tmp.pop(i)
            i -= 1
            n -= 1
            continue
        i += 1

    return removed
    


def solve (x, n):
    out = 0
    tmp = [ord(e) for e in x]
    chars = list(set(tmp[::]))
    chars.sort(reverse=True)

    for char in chars:
        out += remove(tmp, char)

    
    print(out)


solve(x,n)