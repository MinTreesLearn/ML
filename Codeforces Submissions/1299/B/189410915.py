n = int(input())

if n%2 != 0:
        print("NO")
else:
        pts = []

        for i in range(n):
                l = [int(x) for x in input().split(" ")]
                a,b = l[0], l[1]
                pts.append((a,b))

        cx, cy = None, None

        ans = "YES"

        for i in range(n//2):
                x = pts[i][0] + pts[i+n//2][0]
                y = pts[i][1] + pts[i+n//2][1]
                if cx is None:
                        cx = x
                        cy = y
                else:
                        if cx != x or cy != y:
                                ans = "NO"

        print(ans)