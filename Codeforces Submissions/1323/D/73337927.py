import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
L = max(A).bit_length()+1

ans = 0
for l in range(L+1):
    A1 = []
    A2 = []
    for a in A:
        if a&(1<<l):
            A1.append(a)
        else:
            A2.append(a)
    A = A2 + A1

    D = 1<<(l+1)

    i1 = N
    i2 = N
    i3 = N
    k = 0
    for i, a in enumerate(A):
        while i1 > 0 and a%D + A[i1-1]%D >= D//2:
            i1 -= 1
        while i2 > 0 and a%D + A[i2-1]%D >= D:
            i2 -= 1
        while i3 > 0 and a%D + A[i3-1]%D >= D//2*3:
            i3 -= 1
        k += (i2 - i1) + (N - i3)
        if i1 <= i < i2 or i3 <= i < N:
            k -= 1
    if k%4 != 0:
        ans += D//2

print(ans)  