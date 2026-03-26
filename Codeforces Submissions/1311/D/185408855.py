from math import inf,floor,ceil

answers=[]

smallest_prime_factor=[0]*(2*10**4+1)
primes=[]

for i in range(2,2*10**4+1):
    if smallest_prime_factor[i]==0:
        smallest_prime_factor[i]=i
        primes.append(i)
    j=0
    while i*primes[j]<=2*10**4:
        smallest_prime_factor[i*primes[j]]=primes[j]
        if primes[j]==smallest_prime_factor[i]:break
        j+=1

T=int(input())

for test_i in range(T):
    A,B,C=map(int,input().split())

    ans_moves=inf
    ans_vals=None

    for b_val in range(1,11000+1):
        c_val=min([b_val*(floor(C/b_val)+add) for add in [-1,0,1]],key=lambda m:abs(m-C))

        prime_factorization=[]
        b_val2=b_val
        
        while b_val2!=1:
            prime_factor=smallest_prime_factor[b_val2]
            exponent=0

            while b_val2%prime_factor==0:
                b_val2//=prime_factor
                exponent+=1

            prime_factorization.append([prime_factor,exponent])

        factors=[1]

        for prime,exponent in prime_factorization:
            for i in range(len(factors)):
                for count in range(1,exponent+1):
                    factors.append(factors[i]*prime**count)

        a_val=min(factors,key=lambda factor:abs(factor-A))

        vals=[a_val,b_val,c_val]
        moves=sum(abs(new-old) for new,old in zip(vals,[A,B,C]))

        if moves<ans_moves:
            ans_moves=moves
            ans_vals=vals

    answers.append([ans_moves,ans_vals])

for moves,vals in answers:
    print(moves)
    print(*vals)