import java.io.*;
import java.util.*;

public class Main implements Runnable {
    static boolean use_n_tests = false;
    static int stack_size = 1 << 27;
    static long modulo = 1_000_000_007;

    void solve(FastScanner in, PrintWriter out, int testNumber) {
        long x0, y0;
        x0 = in.nextLong();
        y0 = in.nextLong();
        long ax, ay;
        ax = in.nextLong();
        ay = in.nextLong();
        long bx, by;
        bx = in.nextLong();
        by = in.nextLong();

        long xs, ys;
        xs = in.nextLong();
        ys = in.nextLong();
        long t;
        t = in.nextLong();

        List<Long> pts = new ArrayList<>();
        long prevDist = Long.MAX_VALUE;
        while (true) {
            long curDist = dist(x0, y0, xs, ys);
            if (curDist <= t) {
                pts.add(x0);
                pts.add(y0);
            } else if (curDist > prevDist) {
                break;
            }
            prevDist = curDist;
            long x1 = ax * x0 + bx;
            long y1 = ay * y0 + by;
            x0 = x1;
            y0 = y1;
        }

        int ans = getAnswer(pts, t, xs, ys);
        Collections.reverse(pts);
        for (int i = 0; i < pts.size(); i += 2) {
            long tmp = pts.get(i);
            pts.set(i, pts.get(i + 1));
            pts.set(i + 1, tmp);

        }
        int ans1 = getAnswer(pts, t, xs, ys);
        out.println(Math.max(ans, ans1));
    }

    int getAnswer(List<Long> pts, long t1, long x, long y) {
        int ans = 0;
        for (int i = 0; i < pts.size(); i += 2) {
            long start = dist(pts.get(i), pts.get(i + 1), x, y);
            long t = t1 - start;
            int c = 1;
            for (int j = i + 2; j < pts.size() && t > 0; j += 2) {
                long extra = dist(pts.get(j - 2), pts.get(j - 1), pts.get(j), pts.get(j + 1));
                if (extra <= t) {
                    t -= extra;
                    c++;
                } else {
                    break;
                }
            }
            ans = Math.max(ans, c);
        }
        return ans;
    }

    // ****************************** template code ***********

    long dist(long x0, long y0, long x1, long y1) {
        return Math.abs(x0 - x1) + Math.abs(y0 - y1);
    }

    static class Range {
        int l, r;
        int id;

        public int getL() {
            return l;
        }

        public int getR() {
            return r;
        }

        public Range(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
        }
    }

    static class Array {
        static Range[] readRanges(int n, FastScanner in) {
            Range[] result = new Range[n];
            for (int i = 0; i < n; i++) {
                result[i] = new Range(in.nextInt(), in.nextInt(), i);
            }
            return result;
        }

        static public Integer[] read(int n, FastScanner in) {
            Integer[] out = new Integer[n];
            for (int i = 0; i < out.length; i++) {
                out[i] = in.nextInt();
            }
            return out;
        }

        static public int[] readint(int n, FastScanner in) {
            int[] out = new int[n];
            for (int i = 0; i < out.length; i++) {
                out[i] = in.nextInt();
            }
            return out;
        }
    }

    class Graph {
        List<List<Integer>> create(int n) {
            List<List<Integer>> graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }
            return graph;
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream io) {
            br = new BufferedReader(new InputStreamReader(io));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    void run_t_tests() {
        int t = in.nextInt();
        int i = 0;
        while (t-- > 0) {
            solve(in, out, i++);
        }
    }

    void run_one() {
        solve(in, out, -1);
    }

    @Override
    public void run() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        if (use_n_tests) {
            run_t_tests();
        } else {
            run_one();
        }
        out.close();
    }

    static FastScanner in;
    static PrintWriter out;

    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(null, new Main(), "", stack_size);
        thread.start();
        thread.join();
    }
}