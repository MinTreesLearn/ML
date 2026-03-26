for i in range(int(input())):
    a,b,p=map(int, input().split())
    ro=str(input())
    road=list(ro)
    l=len(road)
    node=[]
    bol=(road[-1]=="A")
    if bol:
        cou=0
        node.append([l-1,1])
    else:
        cou=1
        node.append([l-1,0])
    for j in range(l-1,0,-1):
        if road[j-1]==road[j]:
            pass
        else:
            node.append([j,cou])
            cou=abs(cou-1)
    if road[0]!=road[1]:
        node.append([0,abs(node[0][1]-1)])
    if len(node)>=2 and node[0]==node[1]:
        node.pop(0)
    if len(node)>=2 and node[0][0]==node[1][0]:
        node.pop(0)
    summ=0
    boll=True
    for x in range(len(node)):
        summ+=[b,a][node[x][1]]
        if summ>p:
            t=x
            boll=False
            break
    if boll:
        print(1)
    else:
        print(node[t][0]+1)



