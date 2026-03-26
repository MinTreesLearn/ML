import sys

for i in range(int(sys.stdin.readline())):
    s = sys.stdin.readline().strip()
    s += 'R'

    m = 0
    lc = 1

    for j in s:
        if j == 'L':
            lc += 1
            continue
        
        m = max(lc, m)
        lc = 1
    
    print(m)
