n = int(input())

teachs = list(map(int,input().split()))
studs = list(map(int,input().split()))

diffs = [teachs[i]-studs[i] for i in range(n)]


res = 0


diffs.sort()

# print(diffs)

l , r = 0 , n - 1 

while l < r:


    if  diffs[l] > -diffs[r]:
        res += r - l
        r -= 1
    else:
        l += 1

print(res)

