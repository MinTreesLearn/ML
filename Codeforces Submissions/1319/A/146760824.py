n = int(input())
mass_1 = list(map(int, input().split()))
mass_2 = list(map(int, input().split()))

counter_1 = 0
counter_2 = 0

for i in range(n):
    if mass_1[i] == mass_2[i]:
        pass
    else:
        if mass_1[i] == 1:
            counter_1 += 1
        if mass_2[i] == 1:
            counter_2 += 1

if counter_2 < counter_1:
    print(1)
elif counter_1 == counter_2 == 0:
    print(-1)
elif counter_2 == counter_1:
    print(2)
elif counter_1 == 0:
    print(-1)
else:
    result = counter_2 // counter_1 + 1
    print(int(result))
