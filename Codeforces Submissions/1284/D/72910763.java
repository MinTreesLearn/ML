import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jaynil
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public static void add(TreeMap x, int p) {
            x.put(p, (int) x.getOrDefault(p, 0) + 1);
        }

        public static void remove(TreeMap x, int p) {
            int cnt = (int) x.get(p) - 1;
            if (cnt == 0) {
                x.remove(p);
            } else x.put(p, cnt);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            ArrayList<node> a = new ArrayList<>();
            ArrayList<node> b = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int p = in.nextInt();
                int q = in.nextInt();
                int r = in.nextInt();
                int s = in.nextInt();
                a.add(new node(p, r, s, 1));
                a.add(new node(q, r, s, 0));
                b.add(new node(r, p, q, 1));
                b.add(new node(s, p, q, 0));
            }
            Collections.sort(a, (x, y) -> Integer.compare(x.x, y.x) != 0 ? Integer.compare(x.x, y.x) : Integer.compare(y.st, x.st));
            TreeMap<Integer, Integer> start = new TreeMap<Integer, Integer>();
            TreeMap<Integer, Integer> end = new TreeMap<Integer, Integer>();
            for (int i = 0; i < a.size(); i++) {
                if (a.get(i).st == 1) {
                    if (!start.isEmpty()) {
                        int ss = Math.max(start.lastKey(), a.get(i).s);
                        int ee = Math.min(end.firstKey(), a.get(i).e);
                        if (ss > ee) {
                            out.println("NO");
                            return;
                        }
                    }
                    add(start, a.get(i).s);
                    add(end, a.get(i).e);
                } else {
                    remove(start, a.get(i).s);
                    remove(end, a.get(i).e);
                }
            }
            Collections.sort(b, (x, y) -> Integer.compare(x.x, y.x) != 0 ? Integer.compare(x.x, y.x) : Integer.compare(y.st, x.st));
            for (int i = 0; i < b.size(); i++) {
                if (b.get(i).st == 1) {
                    if (!start.isEmpty()) {
                        int ss = Math.max(start.lastKey(), b.get(i).s);
                        int ee = Math.min(end.firstKey(), b.get(i).e);
                        if (ss > ee) {
                            out.println("NO");
                            return;
                        }
                    }
                    add(start, b.get(i).s);
                    add(end, b.get(i).e);
                } else {
                    remove(start, b.get(i).s);
                    remove(end, b.get(i).e);
                }
            }
            out.println("YES");
        }

        class node {
            int x;
            int s;
            int e;
            int st;

            node(int x, int s, int e, int start) {
                this.x = x;
                this.s = s;
                this.e = e;
                this.st = start;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

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
}

