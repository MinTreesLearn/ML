t = int(input())

for case in range(t):
    a, b, p = map(int, input().split(' '))
    s = input()
    
    i = len(s) - 1
    if s[i-1] == 'A':
        cost = a
    elif s[i-1] == 'B':
        cost = b

    if cost > p:
        print(i+1)
        continue
    
    i -= 1
    while i >= 1:
        if s[i-1] == 'A' and s[i] == 'B':
            if cost + a > p:
                break
            cost += a

        elif s[i-1] == 'B' and s[i] == 'A':
            if cost + b > p:
                break
            cost += b

        i -= 1

    print(i+1)
