n = int(input())
s = input()
while len(s) > 1:
    checker = 0
    for letter in 'zyxwvutsrqponmlkjihgfedcb':
        # print(letter, end='')
        if letter in s:
            for i in range(0, len(s)):
                a = i-1
                b = i+1
                neighbours = []
                if a >= 0:
                    neighbours.append(s[a])
                if b < len(s):
                    neighbours.append(s[b])

                if s[i] == letter and chr(ord(s[i])-1) in neighbours:
                    s = s[:i] + s[i+1:]
                    checker = 1
                    break
            
            if checker == 1:
                break
    # print()
    if checker == 0:
        # print(s)
        break
print(n-len(s))
    