n = int(input())
s = input()

for maxElement in sorted(list(s), reverse=True):
    prev = chr(ord(maxElement)-1)

    edited = False

    for i in range(len(s)):
        if s[i] == maxElement:
            if i==0 and i+1<len(s):
                if s[i+1] == prev:
                    s = s[i+1:]
                    edited = True
                    break
    
            elif i==len(s)-1 and i-1>=0:
                if s[i-1] == prev:
                    s = s[:i]
                    edited = True
                    break
            
            elif i-1>=0 and i+1<len(s):
                if s[i-1] == prev or s[i+1] == prev:
                    s = s[:i] + s[i+1:]
                    edited = True
                    break

    

print(n-len(s))