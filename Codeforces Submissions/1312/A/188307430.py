times = int(input())
answer = list()

for i in range(times):
    a, b = map(int, input().split())
    if a%b == 0:
        answer.append('YES')
    else:
        answer.append('NO')

for i in answer:
    print(i)