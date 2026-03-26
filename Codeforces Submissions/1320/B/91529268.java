import java.io.*;
import java.util.*;

public class Main implements Runnable {
    static boolean use_n_tests = false;
    static int stack_size = 1 << 27;
    static long mod = 1_000_000_007;

    void solve(FastScanner in, PrintWriter out, int testNumber) {
        int n, m;
        n = in.nextInt();
        m = in.nextInt();
        List<Integer>[] graph = new ArrayList[n];
        List<Integer>[] inverseg = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            inverseg[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int v, u;
            v = in.nextInt() - 1;
            u = in.nextInt() - 1;
            graph[v].add(u);
            inverseg[u].add(v);
        }
        int q;
        q = in.nextInt();
        int[] p = new int[q];
        for (int i = 0; i < p.length; i++) {
            p[i] = in.nextInt();
        }

        int[] distance = new int[n];
        Deque<Integer> deq = new ArrayDeque<>();
        deq.addLast(p[q - 1] - 1);
        boolean[] mark = new boolean[n];
        while (!deq.isEmpty()) {
            int v = deq.pollFirst();
            mark[v] = true;
            for (int x : inverseg[v]) {
                if (!mark[x]) {
                    distance[x] = distance[v] + 1;
                    deq.addLast(x);
                    mark[x] = true;
                }
            }
        }
        int ansMin = 0;
        int ansMax = 0;

        for (int i = 1; i < p.length; i++) {
            int v = p[i - 1] - 1;
            int u = p[i] - 1;
            if (distance[u] > distance[v] - 1) {
                ansMin++;
                ansMax++;
            } else {
                for (int j = 0; j < graph[v].size(); j++) {
                    int w = graph[v].get(j);
                    if (w != u && distance[w] == distance[v] - 1) {
                        ansMax++;
                        break;
                    }
                }
            }
        }
        out.println(ansMin + " " + ansMax);
    }

    // ****************************** template code ***********

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