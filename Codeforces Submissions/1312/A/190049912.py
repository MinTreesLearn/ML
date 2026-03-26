test = int(input())
for _ in range(test):
    a,b = map(int, input().split())
    if a % b ==0:
        print("YES")
    else:
        print("NO")
    