def factor(n: int) -> bool:
    count = 0
    mul = []
    i = 2
    while(i*i <= n):
        if (n%i==0):
            j = findOhterFactor(i, n)
            if(j):
                mul.append(i)
                mul.append(j)
                mul.append(n//i//j)
                return mul

        i+=1
    return []

def findOhterFactor(i: int, n: int) -> int:
    j = 2
    f = n//i
    while (j*j<=f):
        if(f%j==0):
            o = f//j
            if (j != i and o!=i and o!=j):
                return j
        j+=1
    return 0


def solve() -> None:
    t = int(input())
    for __ in range(t):
        n = int(input())
        arr = factor(n)
        if (len(arr)):
            print("Yes")
            print(' '.join(map(str, arr)))
        else:
            print("No")












if __name__ == '__main__':
    solve()

