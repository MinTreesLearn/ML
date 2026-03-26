T = int(input())
def Deadline(n,d):
    if ((n//2+1)*(n//2-n)+d <=0):
        print("YES")
    else:
        print("NO")
for x in range (T):
    n,d = map(int,input().split())
    Deadline(n,d)