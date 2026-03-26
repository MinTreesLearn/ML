t=int(input(""))
def test(l):
    a,b=int(l[0]),int(l[1])
    if a%b==0:
        return "YES"
    else:
        return "NO"


l=[]
for i in range(t):
    s=input("").split(" ")
    
    c=test(s)
    l.append(c)
for j in range(len(l)):
    print(l[j])
