from sys import stdin, gettrace, stdout

if not gettrace():
    def input():
        return next(stdin)[:-1]


def main():
    n = int(input())
    aa = [int(a) for a in input().split()]
    sum = [0]
    for a in aa:
        sum.append(sum[-1] + a)
    def mean(i,j):
        return (sum[j] - sum[i])/(j - i)
    stk = []
    for i in range(n):
        stk.append((i, i+1))
        while len(stk) > 1 and mean(*stk[-2]) >= mean(*stk[-1]):
            _, j = stk.pop()
            i, _ = stk.pop()
            stk.append((i, j))
    for i,j in stk:
        v = str(mean(i,j))+'\n'
        for k in range(j-i):
            stdout.write(v)

if __name__ == "__main__":
    main()