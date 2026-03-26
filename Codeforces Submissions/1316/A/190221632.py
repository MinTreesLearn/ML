a = int(input())
for i in range(a):
    q, s = map(int, input().split(' '))
    *w, = map(int, input().split(' '))
    print(min(s, sum(w)))