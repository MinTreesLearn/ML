for i in range(int(input())):
    a = int(input())
    if(a%2==0):
        print("1"*(a//2))
    else:
        print('7'+'1'*((a-3)//2))