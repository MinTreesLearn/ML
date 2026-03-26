
def solution(n,d,piles):
    maxi = piles[0]
    for idx,pile in enumerate(piles):
        if idx == 0:
            continue
        
        while (piles[idx] > 0) and (d - idx) >= 0:
            d -= idx 
            piles[idx] -= 1
            maxi += 1

    return maxi


t = int(input())
while t > 0:
    t -= 1
    n,d = [int(x) for x in input().split()]
    piles = [int(x) for x in input().split()] 
    print(solution(n,d, piles))

    
