'''
3 4 ok
3 5 no
3 6 ok
3 7 no
3 8 ok

'''
import sys
input = sys.stdin.readline

t=int(input())
for _ in range(t):
  n,m=map(int,input().split())
  print("YES" if n%m==0 else "NO")