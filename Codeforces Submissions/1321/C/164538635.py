n = int(input())
ak = input()
co = 0
n1 = n
while True:
    max1 = 'a'
    maxi = -1

    for i in range(n):
        if i + 1 < n and ak[i] == chr(ord(ak[i + 1]) + 1) and max1 <= ak[i]:
            maxi = i
            max1 = ak[i]
        if i - 1 >= 0 and ak[i] == chr(ord(ak[i - 1]) + 1) and max1 <= ak[i]:
            maxi = i
            max1 = ak[i]

    if maxi == -1:
        break

    ak = ak[:maxi] + ak[maxi + 1:]
    
    n = n - 1
print(n1-n)
    
    
 
    
    
    
    
    
    
