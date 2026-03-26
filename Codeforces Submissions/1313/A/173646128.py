for _ in range(int(input())):
    a, b, c = map(lambda x : min(int(x), 4), input().split())
    res = 0
    if a:
        a -= 1
        res += 1
    if b:
        b -= 1
        res += 1
    if c:
        c -= 1
        res += 1
    cnt = [0] * 4
    for x in a, b, c:
        cnt[x] += 1
    cnt = ''.join(map(str, cnt))
    if cnt == '0003':
        res = 7
    elif cnt in ['0012', '0021', '0030']:
        res = 6
    elif cnt in ['0201', '0210', '0102', '0120', '0111']:
        res = 5
    elif cnt in ['1200', '0300', '1020', '1002', '1110', '1101', '1011']:
        res += 1
    print(res)
 			  			  				 		 	  		  	  	