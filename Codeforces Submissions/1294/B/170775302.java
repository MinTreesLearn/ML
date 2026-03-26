import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CollectingPackages {
    static PrintWriter pw;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Point> points = new ArrayList<>();
            for (int p = 0; p < n; p++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                points.add(new Point(x, y));
            }
            Collections.sort(points);
            if (!test(points)) {
                pw.println("NO");
            }
        }

        pw.close();
    }

    static boolean test(ArrayList<Point> points) {
        Point pos = new Point(0, 0);

        StringBuilder sb = new StringBuilder();
        for (Point p : points) {
            if (p.x >= pos.x && p.y >= pos.y) {
                sb.append(diff(pos, p));
                pos = p;
            } else return false;
        }

        pw.println("YES");
        pw.println(sb);
        return true;
    }

    static class Point implements Comparable<Point> {
        public int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            int xComp = Integer.compare(x, o.x);
            if (xComp != 0) return xComp;
            else return Integer.compare(y, o.y);
        }
    }
    static StringBuilder diff(Point p1, Point p2) {
        int xDiff = p2.x - p1.x;
        int yDiff = p2.y - p1.y;
        StringBuilder res = new StringBuilder();
        res.append("R".repeat(Math.max(0, xDiff)));
        res.append("U".repeat(Math.max(0, yDiff)));
        return res;
    }
}