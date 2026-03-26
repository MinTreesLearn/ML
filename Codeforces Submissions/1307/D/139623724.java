import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.TreeMap;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.Collections;
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
        DCowAndFields solver = new DCowAndFields();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCowAndFields {
        int n;
        int m;
        int k;
        int[] sp;
        ArrayList<Integer>[] g;
        int[] dist;
        boolean[] vis;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            pre(in);
            int[] d1 = bfs(0);
            int[] d2 = bfs(n - 1);
            int ini = d1[n - 1];
            ArrayList<Pair> list = new ArrayList<>();
            TreeMap<Pair, Integer> hm = new TreeMap<>();
            for (int a : sp) {
                list.add(new Pair(d1[a], d2[a]));
                push(hm, new Pair(d2[a], d1[a]), 1);
            }
            int max = 0;
            Collections.sort(list);
            for (int i = 0; i < k - 1; i++) {
                Pair p = list.get(i);
                pull(hm, new Pair(p.b, p.a), 1);
                Pair p2 = hm.lastKey();
                int val = Math.min(ini, Math.min(p.a + p.b, Math.min(p2.a + p2.b, p.a + 1 + p2.a)));
                max = Math.max(val, max);
            }
            int ans = Math.min(max, ini);
            out.println(ans);
        }

        void push(TreeMap<Pair, Integer> map, Pair k, int v) {
            //map[k] += v;
            if (!map.containsKey(k))
                map.put(k, v);
            else
                map.put(k, map.get(k) + v);
        }

        void pull(TreeMap<Pair, Integer> map, Pair k, int v) {
            //assumes map[k] >= v
            //map[k] -= v
            int lol = map.get(k);
            if (lol == v)
                map.remove(k);
            else
                map.put(k, lol - v);
        }

        int[] bfs(int st) {
            int[] d = new int[n];
            Arrays.fill(d, Integer.MAX_VALUE);
            Queue<Integer> q = new LinkedList<>();
            q.add(st);
            d[st] = 0;
            while (!q.isEmpty()) {
                int p = q.poll();
                for (int a : g[p]) {
                    if (d[a] > d[p] + 1) {
                        d[a] = d[p] + 1;
                        q.add(a);
                    }
                }
            }
            return d;
        }

        void pre(InputReader in) {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            sp = new int[k];
            for (int i = 0; i < k; i++) {
                sp[i] = in.nextInt() - 1;
            }
            g = new ArrayList[n];
            dist = new int[n];
            vis = new boolean[n];
            for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                g[a].add(b);
                g[b].add(a);
            }
        }

        class Pair implements Comparable<Pair> {
            int a;
            int b;

            Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public int hashCode() {
                return Objects.hash(a, b);
            }

            public boolean equals(Object obj) {
                Pair that = (Pair) obj;
                return a == that.a && b == that.b;
            }

            public String toString() {
                return "[" + a + ", " + b + "]";
            }

            public int compareTo(Pair v) {
                return a - v.a;
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

        public void println(int i) {
            writer.println(i);
        }

    }
}

