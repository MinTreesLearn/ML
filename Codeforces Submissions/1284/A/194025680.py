# Defines
lmp = lambda:list(map(int, input().split()))
mp = lambda:map(int, input().split())
intp = lambda:int(input())
inp = lambda:input()
finp = lambda:float(input())
linp = lambda:input().split()

# Input
n, m = mp()
s = linp()
t = linp()
q = intp()
for i in range(q):
    y = intp()

    # Slove
    s1 = y % n - 1
    s2 = y % m - 1
    

    # Output
    print(s[s1] + t[s2])
