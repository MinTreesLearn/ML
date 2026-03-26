from sys import stdin, stdout

n = int(stdin.readline())
s = stdin.readline()

alphabet = ['z', 'y', 'x', 'w', 'v', 'u', 't', 's','r', 'q', 'p','o', 'n',
            'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a']

for c in range(25):
    i = 0
    while i < len(s):
        if len(s) == 1:
            break
        if s[i] == alphabet[c]:
            if i == 0:
                if s[1] == alphabet[c+1]:
                    s = s[1:]
                    i-= 1
            elif i == len(s) - 1:
                if s[-2] == alphabet[c+1]:
                    s = s[:i]
                    i -= 1
            elif s[i-1] == alphabet[c+1] or s[i+1] == alphabet[c+1]:
                s = s[:i] + s[i+1:]
                i -= 1
        i += 1
    
    i = len(s)-1
    while i >= 0:
        if len(s) == 1:
            break
        if s[i] == alphabet[c]:
            if i == 0:
                if s[1] == alphabet[c+1]:
                    s = s[1:]
                    i+= 1
            elif i == len(s) - 1:
                if s[-2] == alphabet[c+1]:
                    s = s[:i]
                    i += 1
            elif s[i-1] == alphabet[c+1] or s[i+1] == alphabet[c+1]:
                s = s[:i] + s[i+1:]
                i += 1
        i -= 1

s = s.strip()

stdout.write(str(n - len(s)))
