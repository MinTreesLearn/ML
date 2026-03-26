n = int(input())
s = input()
for i in range(26, 0, -1):
    symb1 = chr(ord('a')+i)
    symb2 = chr(ord('a')+i-1)
    x1, x2 = symb1+symb2, symb2+symb1
    while s.find(x1)!=-1:
        s = s.replace(symb1+symb2, symb2)
    while s.find(x2)!=-1:
        s = s.replace(symb2+symb1, symb2)
print(n-len(s))