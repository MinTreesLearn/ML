import math
n, m = map(int, input().split())
result = math.factorial(n+(2*m)-1)//(math.factorial(2*m)*math.factorial(n-1))
print(int(result) % (1000000007))
