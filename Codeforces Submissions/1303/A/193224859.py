t = int(input())
for i in range(t):
  s = input()
  if ('1' in s) == True:
    l = s.index('1')
    r = s.rindex('1')
    s = s[l:r].count('0')
    print(s)
  else:
    print(0)