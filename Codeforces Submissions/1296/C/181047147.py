t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    prefix = {(0, 0):-1}
    cur = [0, 0]
    max_len = float('inf')
    answer = [-1, -1]
    for idx, char in enumerate(s):
        if char == "U":
            cur[1] += 1
        elif char == "L":
            cur[0] -= 1
        elif char == "R":
            cur[0] += 1
        else:
            cur[1] -= 1
        
        key = tuple(cur)
        if key in prefix and idx - prefix[key]+1 < max_len:
            max_len = idx - prefix[key] + 1
            answer = [prefix[key]+1, idx]
        
        prefix[key] = idx
    
    if answer == [-1, -1]:
        print(-1)
    else:
        # print(max_len, answer)
        print(answer[0] + 1, answer[1] + 1)



