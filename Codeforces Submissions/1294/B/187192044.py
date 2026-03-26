def main():
    for t in range(int(input())):
        n=int(input())
        a=[]
        for tt in range(n):
            a.append(list(map(int,input().split())))
        a.sort()
        x,y=0,0
        z=""
        h=True
        for i in a:
            if i[0]-x>=0 and i[1]-y>=0:
                z=z+"R"*(i[0]-x)
                z=z+"U"*(i[1]-y)
                x,y=i[0],i[1]
            else:
                h=False
                print("NO")
                break
        if h:
            print("YES")
            print(z)

main()

#la manera de ve si es posible o no es que no haya niuno mas alto que otro y mas a la izquierdaq wuee el otro.
#osea que todos los qliaos arriba de una caja esten arriba o a la derecha.
#el algoritmo es solo ir al que mas cerca este a la derecha, si es imposibe printea NO.