n = int(input())
st = input()
s = []
for i in st:
    s.append(i)

alph = []
for i in range(26):
    alph.append(chr(ord("a")+i))
alnums = [0] * len(s)
for i in range(len(s)):
    alnums[i] = alph.index(s[i])

mxc = []
for i in s:
    ind = alph.index(i)
    if not (ind in mxc) and ind != 0:
        mxc.append(ind)
mxc.sort()
mxc.reverse()
k = 0

while mxc:
    f = True
    for i in range(len(s)):

        if alph.index(s[i]) == mxc[0]:

            
            if i+1 < len(alnums) and alnums[i] - 1 == alnums[i+1]:
                f = False

                del s[i]
                del alnums[i]

                k += 1
                break
            if i-1>=0 and alnums[i] - 1 == alnums[i-1]:
                f = False

                del s[i]
                del alnums[i]

                k += 1
                break
    if f:
        del mxc[0]
print(k)