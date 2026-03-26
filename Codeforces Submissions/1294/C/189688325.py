import math
def primeFactors(n,arr):
	while(n%2==0):
		arr.append(2)
		n = n // 2
	for i in range(3,int(math.sqrt(n))+1,2):
		while n % i== 0:
			arr.append(i)
			n = n // i
	if n > 2:
		arr.append(n) 
	return arr 
from collections import Counter
t=int(input())
while(t):
    t-=1 
    n=int(input())
    n1=n
    arr1=[] 
    ct=[]
    arr1=primeFactors(n,arr1)
    arr=list(Counter(arr1).keys())
    ct=list(Counter(arr1).values())
    ans=[] 
    if(len(arr)>=3):
        ans.append(arr[0]**(ct[0]))
        ans.append(arr[1]**(ct[1]))
        if(n//((arr[0]**(ct[0]))*(arr[1]**(ct[1]))) not in ans and n//((arr[0]**(ct[0]))*(arr[1]**(ct[1])))!=1):
            ans.append(n//((arr[0]**(ct[0]))*(arr[1]**(ct[1])))) 
            print("YES")
            print(*ans)
        else:
            print("NO")
    else:
        ans.append(int(arr[0]))
        if(ct[0]-1>=2):
            ans.append(int(arr[0]*arr[0])) 
            if(n/(arr[0]*arr[0]*arr[0])== n//(arr[0]*arr[0]*arr[0]) and n//(arr[0]*arr[0]*arr[0]) !=1):
                if(n//(arr[0]*arr[0]*arr[0]) not in ans ):
                    ans.append(int(n//(arr[0]*arr[0]*arr[0]))) 
                    print("YES")
                    print(*ans)
                else:
                    print("NO")
            else:
                print("NO") 
        else:
            if(len(arr)==1):
                print("NO")
            else:
                ans.append(int(arr[1])) 
                if(n/(arr[0]*arr[1])==n//(arr[0]*arr[1]) and n//(arr[0]*arr[1])!=1):
                    if(n//(arr[0]*arr[1]) not in ans):
                        ans.append(int(n//(arr[0]*arr[1]))) 
                        print("YES")
                        print(*ans)
                    else:
                        print("NO")
                else:
                    print("NO")