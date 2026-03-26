#from sys import stdin
#input = stdin.readline
#// - remember to add .strip() when input is a string

n = int(input())

lets = list(input().strip())

a = []
b = []
binary_ans = []

flag = True

for i in lets:

  if len(a) == 0:

    a.append(i)
    binary_ans.append("0")

  elif i >= a[-1]:

    a.append(i)
    binary_ans.append("0")
    
  elif len(b) == 0:

    b.append(i)
    binary_ans.append("1")
    
  elif i >= b[-1]:

    b.append(i)
    binary_ans.append("1")

  else:

    flag = False
    break


if flag:
  print("YES")
  print("".join(binary_ans))

else:

  print("NO")