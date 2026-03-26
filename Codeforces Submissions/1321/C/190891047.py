import sys
input = sys.stdin.readline

n = int(input())
s = list(input()[:-1])
c = 0
for i in range(122, 97, -1):
    n = len(s)
    j = 0
    while j < n:
        if s[j] != chr(i):
            j += 1
        else:
            if (j != 0 and s[j-1] == chr(i-1)) or (j != len(s)-1 and s[j+1] == chr(i-1)):
                c += 1
                n -= 1
                s = s[:j] + s[j+1:]
                j = max(0, j-1)
            else:
                j += 1
print(c)