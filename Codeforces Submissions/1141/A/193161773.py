def main(list):
    res = 0
    if list[1]%list[0]!=0:
        return -1
    else:
        k = list[1]//list[0]
        while k>1:
            if k%3==0: 
                k//=3
                res+=1
            elif k%2==0:
                k//=2
                res+=1
            else:
                return -1
        return res
        

print(main([int(i) for i in input().split()]))