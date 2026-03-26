import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Objects;

public class YetAnotherWalkingRobot {
    static BufferedReader br;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) test();
    }

    static void test() throws Exception {
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        Point p = new Point(0, 0);
        HashMap<Point, Integer> map = new HashMap<>();
        map.put(p, 1);

        int[] min = new int[2];
        min[0] = -1000000000;
        min[1] = 1000000000;
        boolean got = false;
        for (int i = 0; i < n; i++) {
            p = new Point(p.x, p.y);
            if (s.charAt(i) == 'L') p.x--;
            else if (s.charAt(i) == 'R') p.x++;
            else if (s.charAt(i) == 'U') p.y++;
            else p.y--;

            if (map.containsKey(p)) {
                int start = map.get(p);
                int minDist = min[1] - min[0];
                int dist = (i + 1) - start;

                if (dist < minDist) {
                    min[1] = (i + 1);
                    min[0] = start;
                    got = true;
                }
                map.put(p, i + 2);
            } else map.put(p, i + 2);
        }
        if (got) System.out.println(min[0] + " " + min[1]);
        else System.out.println(-1);
    }

    static class Point {
        public long x, y;
        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x && y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }
}