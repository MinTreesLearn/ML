n = int(input())
for i in range(n):
    size = int(input())
    s = input()
    cnt = 0
    temp = s.replace('AP','AA')
    while(temp != s):
        cnt += 1 
        s= temp
        temp = s.replace('AP','AA')
    print(cnt)