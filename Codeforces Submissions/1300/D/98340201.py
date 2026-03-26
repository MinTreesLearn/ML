n = int(input())
x = []
y = []
 
def Len(i):
    return (x[i] - x[i + 1]) ** 2 + (y[i] - y[i + 1]) ** 2
 
def Cross(i, j):
    V1 = [x[i] - x[i+1], y[i] - y[i+1]]
    V2 = [x[j] - x[j+1], y[j] - y[j+1]]
    return V1[0] * V2[1] - V1[1] * V2[0]
 
for i in range(n):
    node = input().split();
    x.append(int(node[0]))
    y.append(int(node[1]))
x.append(x[0])
y.append(y[0])
 
if n % 2:
    print("NO")
else:
    for i in range(n // 2):
        j = i + n // 2;
        if Len(i) != Len(j) or Cross(i, j) != 0:
            print("NO")
            exit()
    print("YES")
 
 
 
	 	 	 		  				  	 	 		 	 					