n = int(input())
output = [ ]
for i in range(n):
    A, B = [int(x) for x in input().split()]

    output.append(A * (len(str(B+1)) - 1))

print(*output, sep = "\n")