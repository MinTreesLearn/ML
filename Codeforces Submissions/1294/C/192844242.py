def sol(n) :
    m = n ;a = 0
    for i in range(2,int(n**(1/2))+1) : 
        if not n%i : a = i; break
    else : print('NO'); return
    n //= a
    for i in range(2,int(n**(1/2))+1) : 
        if not n%i and i!=a : b = i;  break
    else : print('NO'); return 
    n//=b 
    if a*b*n == m and n!=b: print('YES'); print(a,b,n)
    else :  print('NO')
for _ in range(int(input())) : 
    n = int(input())
    sol(n)
    