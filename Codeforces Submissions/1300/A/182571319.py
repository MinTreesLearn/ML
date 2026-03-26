t = int(input()) # t (1≤t≤104) — количество наборов входных данных
for i in range(t):
     n = int(input())
     #kr = input()
     #kr =[int(x) for x in kr]
     a = input()  ; a = a.split()
     a = [int(x) for x in a]
     #s = input()
     sm = sum(a)
     kol = a.count(0)
     if sm + kol == 0:
          kol += 1

     print( kol)