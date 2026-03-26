for _ in range(int(input())):
    s=list(input())
    zero=0
    total=0
    if '1' in s:
        for i in s[s.index('1')::]:
            if i=='0':
                zero+=1
            else:
                total+=zero
                zero=0
    print(total)

