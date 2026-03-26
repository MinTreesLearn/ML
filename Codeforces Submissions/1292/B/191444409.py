import sys
input = sys.stdin.buffer.readline 


    
def process(x0, y0, ax, ay, bx, by, xs, ys, t):
    a, b = ax, bx
    c, d = ay, by
    points = []
    for i in range(60):
        x1 = a**i*x0+((a**i-1)//(a-1))*b
        y1 = c**i*y0+((c**i-1)//(c-1))*d
        if x1 <= 10**17 and y1 <= 10**17:
            points.append([x1, y1]) 
    answer = 0
    for earliest in range(len(points)):
        x1, y1 = points[earliest]
        for latest in range(earliest, len(points)):
            x2, y2 = points[latest]
            for proximate in range(earliest, latest+1):
                x3, y3 = points[proximate]
                t1 = abs(x3-xs)+abs(x1-x3)+abs(x2-x1)+abs(y3-ys)+abs(y1-y3)+abs(y2-y1)
                t2 = abs(x3-xs)+abs(x2-x3)+abs(x2-x1)+abs(y3-ys)+abs(y2-y3)+abs(y2-y1)
                t3 = min(t1, t2)
                if t3 <= t:
                    answer = max(answer, latest-earliest+1)
    sys.stdout.write(f'{answer}\n')
    return

x0, y0, ax, ay, bx, by = [int(x) for x in input().split()]
xs, ys, t = [int(x) for x in input().split()]
process(x0, y0, ax, ay, bx, by, xs, ys, t)