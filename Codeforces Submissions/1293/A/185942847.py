import sys
input=sys.stdin.readline
for i in range(int(input())):
    l=list(map(int,input().split()))
    k=list(map(int,input().split()))
    for i in range(l[0]+1):
        if l[1]+i not in k and l[1]+i<=l[0]:
            print(i)
            break
        elif l[1]-i not in k and l[1]-i>0:
            print(i)
            break