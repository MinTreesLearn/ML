n, k=[int(v) for v in input().split()]
w=[]
q=set()
for j in range(n):
    w.append(input())
q=set(w)
c=set(["S", "E", "T"])
res=0
for j in range(n):
    for z in range(j+1, n):
        eta=[]
        for l in range(k):
            if w[j][l]==w[z][l]:
                eta.append(w[j][l])
            else:
                y=[w[j][l], w[z][l]]
                if "S" not in y:
                    eta.append("S")
                elif "E" not in y:
                    eta.append("E")
                else:
                    eta.append("T")
        eta="".join([str(v) for v in eta])
        #print(eta)
        if eta in q:
            res+=1
print(res//3)