string = input()
l = 0
r = len(string)-1
indices = []

while l < r:
    while string[l] == "(" and string[r] == ")":
        didOp = True
        indices.extend([l+1, r+1])
        l += 1
        r -= 1

    if string[l] != "(":
        l += 1
        
    if string[r] != ")":
        r -= 1 

if indices:
    print(1)
    print(len(indices))
    print(*sorted(indices))
else:
    print(0)
    