for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    s1 = s
    i = 0
    t = 0
    l = []
    while i < n:
          if a[i] >= 0:
              t = t + a[i]
              l.append(a[i])
          else:
              if s1>0 and t+a[i]>0:
                  t = t + a[i]
                  l.append(a[i])
              elif s1>0 and t+a[i]<0:
                  t = 0
                  l = []
              elif s1<0 and t+a[i]>0:
                  break
              else:
                  if t>s1-a[i]:
                      break
                  else:
                      t = 0
                      l = []
          s1 = s1 - a[i]
          i = i + 1

    if len(l)==n:
        t = t - min(l[0],l[-1])
    if t>=s:
        print('NO')
    else:
        print('YES')

