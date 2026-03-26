s = input().split(' ')
n = int(s[0])
m1 = int(s[1]) - 1
m = m1
l = []
s = ""


def f(str1):
    i1 = m + 1
    i2 = m
    while i1 != 0 and i1 != 1:
        if str1[i2] != str1[m - i2]:
            return False
        else:
            i2 -= 1
            i1 -= 2
    return True


for i in range(n):
    obj = input()
    if f(obj):
        s = obj
    else:
        l.append(obj)

while len(l) != 0:
    for obj1 in l:
        l.remove(obj1)
        s1 = obj1[0]
        for obj2 in l:
            m = m1
            s2 = obj2[m]
            if s1 == s2:
                r = obj1 + obj2
                m = len(r) - 1
                if f(r):
                    s = obj1 + s + obj2
                    l.remove(obj2)
print(len(s))
print(s)

		 	 	   			 			 	 	  	   	 	