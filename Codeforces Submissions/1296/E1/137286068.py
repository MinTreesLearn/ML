n = int(input())
s = input()

symbols = [(s[i], i) for i in range(n)]
unsorted = [-1]*n

result = None

odd_unsorted = True
even_unsorted = True

pairs = dict()
for i in range(n):
    pairs[i] = set()

while odd_unsorted or even_unsorted:
    even_unsorted = False
    for i in range(0, 2 * (n//2), 2):
        if symbols[i][0] > symbols[i+1][0]:
            even_unsorted = True
            # check constraints
            if len(pairs[symbols[i][1]].intersection(pairs[symbols[i+1][1]])) != 0:
                result = 'NO'
                break
            pairs[symbols[i][1]].add(symbols[i+1][1])
            pairs[symbols[i+1][1]].add(symbols[i][1])
            symbols[i], symbols[i+1] = symbols[i+1], symbols[i]

    if result:
        break

    odd_unsorted = False
    for i in range(1, 2 * ((n-1)//2) + 1, 2):
        if symbols[i][0] > symbols[i+1][0]:
            odd_unsorted = True
            # check constraints
            if len(pairs[symbols[i][1]].intersection(pairs[symbols[i+1][1]])) != 0:
                result = 'NO'
                break
            pairs[symbols[i][1]].add(symbols[i+1][1])
            pairs[symbols[i+1][1]].add(symbols[i][1])
            symbols[i], symbols[i+1] = symbols[i+1], symbols[i]

    if result:
        break

if not result:
    result = 'YES'

    for i in range(n):
        if unsorted[i] == -1:
            unsorted[i] = 0
        for j in pairs[i]:
            if unsorted[j] == -1:
                unsorted[j] = (unsorted[i]+1) % 2 
            # else:
            #     if unsorted[i] == unsorted[j]:
            #         print('ERROR')

print(result)
if result == 'YES':
    print(*unsorted, sep='')