t = int(input())
for i in range(t):
    n = int(input())
    mas = list(map(int,input().split()))
    min1 = 10**9+10
    max1 = 0
    for i in range(n):
        if mas[i] == -1:
            if i == 0:
                if mas[i+1] != -1:
                    min1 = min(mas[i+1],min1)
                    max1 = max(mas[i+1],max1)
            elif i == n-1:
                if mas[i-1] != -1:
                    min1 = min(mas[i-1],min1)
                    max1 = max(mas[i-1],max1)
            else:
                if mas[i+1] != -1:
                    min1 = min(mas[i+1],min1)
                    max1 = max(max1,mas[i+1])
                if mas[i-1] != -1:
                    min1 = min(mas[i-1],min1)
                    max1 = max(max1, mas[i-1])
    k = (min1+max1)//2
    ans = 0
    for i in range(n):
        if mas[i] == -1:
            mas[i] = k
    for i in range(n-1):
        ans = max(ans,abs(mas[i]-mas[i+1]))
    print(ans, k)