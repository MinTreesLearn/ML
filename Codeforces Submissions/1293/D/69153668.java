import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    void run() throws IOException {
        long x0 = nextLong();
        long y0 = nextLong();
        long ax = nextLong();
        long ay = nextLong();
        long bx = nextLong();
        long by = nextLong();
        long xs = nextLong();
        long ys = nextLong();
        long t = nextLong();
        ArrayList<pair> points = new ArrayList<>();
        points.add(new pair(x0, y0));
        long prev_x = x0;
        long prev_y = y0;
        while (sqrt(prev_x) * sqrt(ax) + sqrt(bx) < sqrt(Long.MAX_VALUE) && sqrt(prev_y) * sqrt(ay) + sqrt(by) < sqrt(Long.MAX_VALUE)) {
            prev_x *= ax;
            prev_x += bx;
            prev_y *= ay;
            prev_y += by;
            points.add(new pair(prev_x, prev_y));
        }
        int best = 0;
        for (int i = 0; i < points.size(); i++) {
            long time = 0;
            pair now = new pair(xs, ys);
            int pos = i;
            int cnt = 0;
            while (pos >= 0 && sqrt(abs(now.x - points.get(pos).x)) + sqrt(abs(now.y - points.get(pos).y)) + sqrt(time) < sqrt(Long.MAX_VALUE) && time + abs(now.x - points.get(pos).x) + abs(now.y - points.get(pos).y) <= t) {
                time += abs(now.x - points.get(pos).x) + abs(now.y - points.get(pos).y);
                cnt++;
                now = new pair(points.get(pos).x, points.get(pos).y);
                pos--;
            }
            pos = i + 1;
            while (pos < points.size() && sqrt(abs(now.x - points.get(pos).x)) + sqrt(abs(now.y - points.get(pos).y)) + sqrt(time) < sqrt(Long.MAX_VALUE) && time + abs(now.x - points.get(pos).x) + abs(now.y - points.get(pos).y) <= t) {
                time += abs(now.x - points.get(pos).x) + abs(now.y - points.get(pos).y);
                cnt++;
                now = new pair(points.get(pos).x, points.get(pos).y);
                pos++;
            }
            best = max(best, cnt);
        }
        pw.println(best);
        pw.close();
    }

    class pair implements Comparable<pair> {
        long x, y;

        public pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(pair o) {
            return -Long.compare(o.x, this.x);
        }
    }


    Scanner sc = new Scanner(System.in);
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    //BufferedReader br = new BufferedReader(new FileReader("downloading.in"));

    StringTokenizer st = new StringTokenizer("");
    PrintWriter pw = new PrintWriter(System.out);
    //PrintWriter pw = new PrintWriter("downloading.out");

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public Main() throws FileNotFoundException {
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}