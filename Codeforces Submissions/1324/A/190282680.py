import os
os.system("cls")  # clear screen

t = int(input())
for T in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    parity = arr[0] % 2
    answer = "YES"
    for x in arr:
        if x % 2 != parity:
            answer = "NO"
            break
    print(answer)
