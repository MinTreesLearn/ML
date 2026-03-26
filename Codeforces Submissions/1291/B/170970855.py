import sys
input = sys.stdin.readline
show = sys.stdout.write

for _ in range(int(input())):
    n = int(input())
    f = False
    arr = list(map(int, input().split()))
    i = 0
    while i<n and arr[i] >= i:
        i+=1
    while i<n:
        if arr[i-1]>arr[i]:
            i+=1
            continue
        else:
            arr[i] = arr[i-1] - 1
            if arr[i] < 0:
                break
            i+=1
    if i==n:
        show("Yes\n")
    else:
        show("No\n")


    
 	  	     			   		  				 	 		