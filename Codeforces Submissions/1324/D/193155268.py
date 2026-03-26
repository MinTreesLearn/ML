size: int = int(input())

diff: list[int] = []

a = list(map(int,input().split()))

b = list(map(int,input().split()))

for i in range(size):
    diff.append(a[i]-b[i])


diff.sort()

l: int = 0
r: int = diff.__len__()-1
ans:int = 0

while l < r :
    if diff[r] + diff[l] > 0 :
        ans += r - l
        r -= 1
    else:
        l += 1

print(ans)
