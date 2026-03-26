t=int(input())
for _ in range(t):
    size=int(input())
    path=input()

    l,res=0,[-1]
    min_length=size+1
    pos_idx={(0,0):-1}
    x,y=0,0
    for r,go in enumerate(path):
        if go=="L":
            x-=1
        elif go=="R":
            x+=1
        elif go=="U":
            y+=1
        else:
            y-=1
        if (x,y) in pos_idx:
            if r-pos_idx[(x,y)]<min_length:
                min_length=r-pos_idx[(x,y)]
                res=[pos_idx[(x,y)]+2,r+1]
        pos_idx[(x,y)]=r
    print(*res)



        


        
        

