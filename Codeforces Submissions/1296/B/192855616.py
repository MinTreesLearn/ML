def f():
    t=int(input())
    for i in range(t):
        n=int(input())
        ans=0
        while True:
            d=(n//10)*10
            ans=ans+d
            n=(n-d)+(d//10)
            if n<10:
                ans=ans+n
                break
        print(ans)

f()
            
        