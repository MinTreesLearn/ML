import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DKuroniAndTheCelebration solver = new DKuroniAndTheCelebration();
        solver.solve(1, in, out);
        out.close();
    }

    static class DKuroniAndTheCelebration {
        int n;
        int m;
        HashSet<Integer>[] g;
        int[] dist;
        boolean[] vis;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            pre(in);

//        TreeSet<Pair> set= new TreeSet<>();
//        for(int i=0;i<n;i++) set.add(new Pair(g[i].size(),i));
            int curr = 0;
            while (true) {

                ArrayList<Integer> list = new ArrayList<>();
                for (int a : g[curr]) list.add(a);
                int s = list.size();
                int val = -1;
                for (int i = 1; i < s; i += 2) {
                    int x = query(list.get(i), list.get(i - 1), in);
                    g[curr].remove(list.get(i));
                    g[curr].remove(list.get(i - 1));
                    if (x != curr) {
                        val = x;
                        break;
                    }
                }
                if (val == -1 && s % 2 == 1) {
                    if (g[curr].size() == 1 && g[list.get(s - 1)].size() == 1) {
                        int x = query(curr, list.get(s - 1), in);
                        curr = x;
                        break;
                    } else {
                        curr = list.get(s - 1);
                        continue;
                    }
                }
                if (val == -1) break;
//            set.remove(new Pair(g[curr].size(),curr));
//            for(int a:g[curr]){
//                set.remove(new Pair(g[a].size(),a));
//            }
                g[val].remove(curr);
                curr = val;
//            set.add(new Pair(g[val].size(),val));
            }
            System.out.println("! " + (curr + 1));
        }

        int query(int u, int v, InputReader in) {
            System.out.println("? " + (u + 1) + " " + (v + 1));
            return in.nextInt() - 1;
        }

        void pre(InputReader in) {
            n = in.nextInt();
            m = n - 1;
            g = new HashSet[n];
            dist = new int[n];
            vis = new boolean[n];
            for (int i = 0; i < n; i++) g[i] = new HashSet<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                if (a == b) continue;
                g[a].add(b);
                g[b].add(a);
            }
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

    }
}

