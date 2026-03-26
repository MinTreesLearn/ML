n = int(input())
dollars = 0
for i in range(n):
    dollars += (1 / n)
    n -= 1
print(dollars)