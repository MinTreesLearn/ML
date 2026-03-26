n = int(input())
s = input()

s = list(s)
cnt = 0
for i in range(25, -1, -1):
    c = chr(97+i)
    j = 0
    while j < len(s):
        if s[j] == c and (j != 0 and ord(s[j-1])+1 == ord(c) or j != len(s)-1 and ord(s[j+1])+1 == ord(c)):
            s.pop(j)
            cnt += 1
            j = -1
        j += 1
print(cnt)