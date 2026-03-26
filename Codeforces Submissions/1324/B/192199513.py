
def palindrome(a):
    n = len(a)
    for i in range(n - 2):
        for j in range(i + 2, n):
            if a[i] == a[j]:
                return True
    return False

t = int(input())
for _ in range(t):
    input()
    a = list(map(int, input().split()))

    if palindrome(a):
        print("YES")
    else:
        print("NO")

   			    		    	   					 	  	