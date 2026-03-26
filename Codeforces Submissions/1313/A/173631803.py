# zdjfhdaskjfhjsdkahfjkdskfjsdkjfhsdfdsfsdfdfd
t = int(input())
for _ in range(t):
  a, b, c = map(int, input().split())
  ans = 0
  if a > 0:
    a -= 1
    ans += 1
  if b > 0:
    b -= 1
    ans += 1
  if c > 0:
    c -= 1
    ans += 1
  cDown = False
  if c > 1:
    if c > 0 and b > 0:
      c -= 1
      b -= 1
      ans += 1
      cDown = True
  if a > 0 and b > 0:
    a -= 1
    b -= 1
    ans += 1
  if c > 0 and b > 0 and not cDown:
    c -= 1
    b -= 1
    ans += 1
  if a > 0 and c > 0:
    a -= 1
    c -= 1
    ans += 1
  if a > 0 and b > 0 and c > 0:
    ans += 1
  print(str(min(7, ans)))
  		 	 	   	   	 						    	