'''
Case 1: All L is ignored
Case 2: All R is ignored

LRLR
Range from [-2,2]
positions = 2--2 + 1

Count R and L
print(R+L + 1)

'''
n=int(input())
s = input().strip()
L = 0
R = 0
for c in s:
  if c == "L":
    L += 1
  else:
    R += 1
print(R + L + 1)