def solve():
    n = int(input())
    a = input().split()

    for i in range(n-2):
        for j in range(i+2, n):
            if a[i] == a[j]:
                print("YES")
                return
    
    print("NO")


for _ in range(int(input())):
    solve()

##########################################
##                                      ##
##      Implemented by brownfox2k6      ##
##                                      ##
##########################################