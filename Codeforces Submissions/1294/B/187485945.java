
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CollectingPackages {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));

        var st = new StringTokenizer(r.readLine());
        var t = Integer.parseInt(st.nextToken());
        for (int i = 0; i < t; i++) {
            st = new StringTokenizer(r.readLine());
            var n = Integer.parseInt(st.nextToken());
            var points = new Point[n];
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(r.readLine());
                points[j] = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            }
            Arrays.sort(points);
            var prevX = 0;
            var prevY = 0;
            var str = new StringBuilder();
            var check = true;
            for (Point p : points) {
                if(p.y<prevY) {
                    check = false;
                    break;
                }
                str.append("R".repeat(Math.max(0, p.x - prevX)));
                str.append("U".repeat(Math.max(0, p.y - prevY)));
                prevY = p.y;
                prevX = p.x;
            }
            if (check) {
                System.out.println("YES\n"+str);
            }
            else {
                System.out.println("NO");
            }
        }
    }

    static class Point implements Comparable<Point> {
        int x;
        int y;
        public Point(int x,int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Point p) {
            if (p.x!=this.x) {
                return Integer.compare(this.x,p.x);
            }
            else {
                return Integer.compare(this.y,p.y);
            }
        }
    }
}