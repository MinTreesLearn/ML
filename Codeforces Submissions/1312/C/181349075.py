T = int (input()) 
for test in range (T):
    n , k =  map (int, input ().split(' '))
    arr = list (map (int, input ().split(' ')))
    mx = max(arr)
    values = list () 
    ind =1 
    arr.sort() 
    arr.reverse()
    while len (arr) > 0 and arr[-1] == 0: 
        arr.pop()
    values.append(1)
    while ind <= mx: 
        ind *= k 
        values.append(ind)
    values.sort()
    ok = True
    while len (arr)>0:
        x = arr.pop()
        if (x == 0 ) :
            break 
        while x > 0: 
            mx = 0 
            for it in values: 
                if it <= x: 
                    mx = it 
            if mx == 0:
                break
            x -= mx 
            values.remove(mx)
        ok&= x ==0 
    print ("YES")  if ok else print ("NO")  

