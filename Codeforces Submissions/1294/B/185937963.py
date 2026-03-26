for i in range(int(input())):
    n=int(input())
    l=[]
    for j in range(n):
        l.append(tuple(map(int,input().split())))
    l.sort()
    for j in range(n-1):
        if l[j][1]>l[j+1][1]:
            print("NO")
            break
    else:
        s="R"*l[0][0]+"U"*l[0][1]
        for j in range(1,n):
            s+="R"*(l[j][0]-l[j-1][0])+"U"*(l[j][1]-l[j-1][1])
        print("YES")
        print(s)
 	         			   	 	      	 			