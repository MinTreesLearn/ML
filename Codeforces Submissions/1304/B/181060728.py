n , m = map (int , input().split (' ')) 
store = set() 
res = "" 
while n>0:
    s = input() 
    if s in store:
        res+= s
        store.remove(s)
    else :
        store.add(str (''.join(reversed(s))))
    n-=1
midl = "" 
for x in store:
    if (x == str( ''.join(reversed(x)))):
        midl=x
        break
print (len(res)*2 + len(midl))
print (res + midl +''.join(reversed(res)))