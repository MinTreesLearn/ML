
def solve():
    x = input()
    n = input()
    if int(x) % 2 != 0:
        print("-1")
        return
    res = 0
    ll = 0
    cur = 0
    for i in range(len(n)):
        if ll >= 0:
            if n[i] == "(":
                ll += 1
            else:
                ll -= 1
                if ll == -1:
                    cur = i
        elif n[i] == ")":
            ll -= 1
        else:
            ll += 1
            if ll == 0:
                res += i - cur + 1
    if ll == 0:
        print(str(res))
    else:
        print("-1")

solve()
			  	 	 				 		 			 	 		 	   	